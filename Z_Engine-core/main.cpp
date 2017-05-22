#include "src\graphics\window.h"
#include "src\maths\maths.h"
#include "src\utils\fileutils.h"
#include "src\graphics\shader.h"

#include "src\graphics\buffers\buffer.h"
#include "src\graphics\buffers\indexbuffer.h"
#include "src\graphics\buffers\vertexarray.h"

#include "src\graphics\renderer2d.h"
#include "src\graphics\simple2drenderer.h"
#include "src\graphics\batchrenderer2d.h"

#include "src\graphics\static_sprite.h"
#include "src\graphics\sprite.h"

#include <vector>
#include <time.h>
#include "src\utils\timer.h"

#define BATCH_RENDERER 1

int main()
{
	using namespace z_engine;
	using namespace graphics;
	using namespace maths;

	Window window("Z_engine", 960, 540);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	Shader shader("src/shaders/basic.vert", "src/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_matrix", ortho);
	//shader.setUniformMat4("ml_matrix", mat4::translation(vec3(4, 3, 0)));

	std::vector<Renderable2D*> sprites;

	srand(time(NULL));

	for (float y = 0; y < 9.0f; y+=0.1f)
	{
		for (float x = 0; x < 16.0f; x+=0.1f)
		{
			sprites.push_back(new 
#if BATCH_RENDERER
				Sprite
#else
				StaticSprite
#endif
				(x,y,0.08f, 0.08f, maths::vec4(rand() % 1000 / 1000.0f,0,1,1)
#if !BATCH_RENDERER
					, shader
#endif
				));
		}

	}

#if BATCH_RENDERER
	Sprite sprite(5, 5, 4, 4, vec4(1, 0, 1, 1));
	Sprite sprite2(7, 1, 2, 3, vec4(0.2, 0, 1, 1));
	BatchRenderer2D renderer;
#else
	StaticSprite sprite(5, 5, 4, 4, vec4(1, 0, 1, 1), shader);
	StaticSprite sprite2(7, 1, 2, 3, vec4(0.2, 0, 1, 1), shader);
	Simple2DRenderer renderer;
#endif

	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	Timer time;
	float timer(0);
	int frames(0);
	while (!window.closed())
	{
		//timer.reset();
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));

#if BATCH_RENDERER
		renderer.begin();
#endif

		for (int i = 0; i < sprites.size(); ++i)
		{
			renderer.submit(sprites[i]);
		}

#if BATCH_RENDERER
		renderer.end();
#endif
		renderer.flush();

		window.update();
		++frames;
		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}
		//printf("%f ms\n", timer.elapsed() * 1000);
	}

	return 0;
}