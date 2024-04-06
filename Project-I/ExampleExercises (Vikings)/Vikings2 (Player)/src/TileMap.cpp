#include "TileMap.h"
#include "Globals.h"
#include "ResourceManager.h"
#include <cstring>

TileMap::TileMap()
{
	map = nullptr;
	width = 0;
	height = 0;
	laser = nullptr;
	face = nullptr;
	img_tiles = nullptr;

	InitTileDictionary();
}
TileMap::~TileMap()
{
	if (map != nullptr)
	{
		delete[] map;
		map = nullptr;
	}
	if (laser != nullptr)
	{
		laser->Release();
		delete laser;
		laser = nullptr;
	}
	if (face != nullptr)
	{
		face->Release();
		delete face;
		face = nullptr;
	}
}
void TileMap::InitTileDictionary()
{
	const int n = TILE_SIZE;

	dict_rect[(int)Tile::BLOCK_SQUARE1_TL] = { 0,  0, n, n };
	dict_rect[(int)Tile::BLOCK_SQUARE1_TR] = { n,  0, n, n };
	dict_rect[(int)Tile::BLOCK_SQUARE1_BL] = { 0, n, n, n };
	dict_rect[(int)Tile::BLOCK_SQUARE1_BR] = { n, n, n, n };
	dict_rect[(int)Tile::BLOCK_SQUARE2_TL] = { 2 * n,  0, n, n };
	dict_rect[(int)Tile::BLOCK_SQUARE2_TR] = { 3 * n,  0, n, n };
	dict_rect[(int)Tile::BLOCK_SQUARE2_BL] = { 2 * n, n, n, n };
	dict_rect[(int)Tile::BLOCK_SQUARE2_BR] = { 3 * n, n, n, n };
	dict_rect[(int)Tile::BLOCK_VERT2_T] = { 4 * n,  0, n, n };
	dict_rect[(int)Tile::BLOCK_VERT2_B] = { 4 * n, n, n, n };
	dict_rect[(int)Tile::BLOCK_HORIZ2_L] = { 5 * n, 0, n, n };
	dict_rect[(int)Tile::BLOCK_HORIZ2_R] = { 6 * n, 0, n, n };
	dict_rect[(int)Tile::BLOCK_BLUE] = { 7 * n, 0, n, n };
	dict_rect[(int)Tile::BLOCK_HORIZ3_L] = { 5 * n, n, n, n };
	dict_rect[(int)Tile::BLOCK_HORIZ3_M] = { 6 * n, n, n, n };
	dict_rect[(int)Tile::BLOCK_HORIZ3_R] = { 7 * n, n, n, n };
	dict_rect[(int)Tile::BLOCK_BEAM_L] = { 0, 2 * n, n, n };
	dict_rect[(int)Tile::BLOCK_BEAM_R] = { n, 2 * n, n, n };

	dict_rect[(int)Tile::LADDER_L] = { 2 * n, 2 * n, n, n };
	dict_rect[(int)Tile::LADDER_R] = { 3 * n, 2 * n, n, n };
	dict_rect[(int)Tile::LADDER_TOP_L] = { 4 * n, 2 * n, n, n };
	dict_rect[(int)Tile::LADDER_TOP_R] = { 5 * n, 2 * n, n, n };

	dict_rect[(int)Tile::LOCK_RED] = { 6 * n, 2 * n, n, n };
	dict_rect[(int)Tile::LOCK_YELLOW] = { 7 * n, 2 * n, n, n };

	dict_rect[(int)Tile::LASER_L] = { 0, 6 * n, n, n };
	dict_rect[(int)Tile::LASER_R] = { 4 * n, 6 * n, n, n };
	
	dict_rect[(int)Tile::LASER_FRAME0] = { 1 * n, 6 * n, n, n };
	dict_rect[(int)Tile::LASER_FRAME1] = { 2 * n, 6 * n, n, n };
	dict_rect[(int)Tile::LASER_FRAME2] = { 3 * n, 6 * n, n, n };

	dict_rect[(int)Tile::FACE_FRAME0] = { 1 * n, 7 * n, n, n };
	dict_rect[(int)Tile::FACE_FRAME1] = { 2 * n, 7 * n, n, n };
	dict_rect[(int)Tile::FACE_FRAME2] = { 3 * n, 7 * n, n, n };
	dict_rect[(int)Tile::FACE_FRAME3] = { 4 * n, 7 * n, n, n };

}
AppStatus TileMap::Initialise()
{
	ResourceManager& data = ResourceManager::Instance();

	if (data.LoadTexture(Resource::IMG_TILES, "images/tileset.png") != AppStatus::OK)
	{
		return AppStatus::ERROR;
	}
	img_tiles = data.GetTexture(Resource::IMG_TILES);

	laser = new Sprite(img_tiles);
	if (laser == nullptr)
	{
		LOG("Failed to allocate memory for laser sprite");
		return AppStatus::ERROR;
	}
	laser->SetNumberAnimations(1);
	laser->SetAnimationDelay(0, ANIM_DELAY);
	laser->AddKeyFrame(0, dict_rect[(int)Tile::LASER_FRAME0]);
	laser->AddKeyFrame(0, dict_rect[(int)Tile::LASER_FRAME1]);
	laser->AddKeyFrame(0, dict_rect[(int)Tile::LASER_FRAME2]);
	laser->SetAnimation(0);

	face = new Sprite(img_tiles);
	if (face == nullptr) {
		LOG("Failed to allocate memory for face sprite");
		return AppStatus::ERROR;
	}
	face->SetNumberAnimations(1);
	face->SetAnimationDelay(0, ANIM_DELAY);
	face->AddKeyFrame(0, dict_rect[(int)Tile::FACE_FRAME0]);
	face->AddKeyFrame(0, dict_rect[(int)Tile::FACE_FRAME1]);
	face->AddKeyFrame(0, dict_rect[(int)Tile::FACE_FRAME2]);
	face->AddKeyFrame(0, dict_rect[(int)Tile::FACE_FRAME3]);
	face->SetAnimation(0);

	return AppStatus::OK;
}
AppStatus TileMap::Load(int data[], int w, int h)
{
	int size = w*h;

	width = w;
	height = h;

	if (map != nullptr)	delete[] map;

	map = new Tile[size];
	if (map == nullptr)	
	{
		LOG("Failed to allocate memory for tile map");
		return AppStatus::ERROR;
	}
	memcpy(map, data, size * sizeof(int));

	return AppStatus::OK;
}
void TileMap::Update()
{
	laser->Update();
	face->Update();
}
void TileMap::Render()
{
	Tile tile;
	Rectangle rc;
	Vector2 pos;

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			tile = map[i * width + j];
			if (tile != Tile::AIR)
			{
				pos.x = (float)j * TILE_SIZE;
				pos.y = (float)i * TILE_SIZE;

				if (tile == Tile::LASER)
				{
					laser->Draw((int)pos.x, (int)pos.y);
				}
				else if (tile == Tile::FACE) {
					face->Draw((int)pos.x, (int)pos.y);
				}
				else{
					rc = dict_rect[(int)tile];
					DrawTextureRec(*img_tiles, rc, pos, WHITE);
				}
			}
		}
	}
}
void TileMap::Release()
{
	ResourceManager& data = ResourceManager::Instance(); 
	data.ReleaseTexture(Resource::IMG_TILES);

	laser->Release();

	dict_rect.clear();
}