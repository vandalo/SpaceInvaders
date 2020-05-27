#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "ModuleFont.h"

ModuleRender::ModuleRender()
{
	camera.x = camera.y = 0;
	camera.w = SCREEN_WIDTH * SCREEN_SIZE;
	camera.h = SCREEN_HEIGHT * SCREEN_SIZE;
}

// Destructor
ModuleRender::~ModuleRender()
{}

// Called before render is available
bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true;
	Uint32 flags = 0;

	if (VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);

	if (renderer == nullptr)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

update_status ModuleRender::PreUpdate(float deltaTime)
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	return UPDATE_CONTINUE;
}

// Called every draw update
update_status ModuleRender::Update(const float deltaTime)
{
	// debug camera
	int speed = 1;

	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		App->renderer->camera.y += speed;

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		App->renderer->camera.y -= speed;

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		App->renderer->camera.x += speed;

	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		App->renderer->camera.x -= speed;

	return UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate(float deltaTime)
{
	SDL_RenderPresent(renderer);
	return UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");

	//Destroy window
	if (renderer != nullptr)
	{
		SDL_DestroyRenderer(renderer);
	}

	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, SDL_Rect rect)
{
	bool ret = true;
	SDL_Rect texture_rect;
	texture_rect.x = rect.x;   // the x coordinate
	texture_rect.y = rect.y;   // the y coordinate
	texture_rect.w = rect.h;  // the width of the texture
	texture_rect.h = rect.w;  // the height of the texture

	SDL_RenderCopy(renderer, texture, nullptr, &texture_rect);
	return ret;
}

bool ModuleRender::Print(unsigned int idFont, const char* text, int x, int y, bool center)
{
	bool ret = true;

	SDL_Rect leter;
	SDL_Rect position;
	Font font = App->font->fonts[idFont];
	if (center) {
		position.y = y - (font.heigth / 2);
		position.x = x - (strlen(text) * font.width / 2) - font.width;
	}

	else {
		position.x = x;
		position.y = y;
	}


	for (int i = 0; text[i] != '\0'; i++) {
		int value = font.fontMap.find(text[i])->second;
		leter.h = font.heigth;
		leter.w = font.width;
		leter.x = value;
		leter.y = font.y;
		position.w = leter.w;
		position.h = leter.h;
		position.x += font.width;
		if (SDL_RenderCopy(renderer, font.surface, &leter, &position) != 0)
		{
			LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
			ret = false;
		}
	}
	return ret;
}

bool ModuleRender::DrawQuad(const SDL_Rect& rect, unsigned int r, unsigned int g, unsigned int b, unsigned int a, bool use_camera)
{
	bool ret = true;

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	SDL_Rect rec(rect);
	if (use_camera)
	{
		rec.x = (int)(camera.x + rect.x * SCREEN_SIZE);
		rec.y = (int)(camera.y + rect.y * SCREEN_SIZE);
		rec.w *= SCREEN_SIZE;
		rec.h *= SCREEN_SIZE;
	}

	if (SDL_RenderFillRect(renderer, &rec) != 0)
	{
		LOG("Cannot draw quad to screen. SDL_RenderFillRect error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}


