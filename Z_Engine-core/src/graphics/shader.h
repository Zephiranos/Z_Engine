#pragma once

#include <iostream>
#include <GL\glew.h>
#include <vector>
#include "../maths/maths.h"
#include "../utils/fileutils.h"

//////////////////////
// Shader class header
//////////////////////

namespace z_engine {
	namespace graphics {

		class Shader
		{
		public:
			GLuint m_ShaderID;
			const char* m_VertPath;
			const char *m_FragPath;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void enable() const;
			void disable() const;

			void setUniform1f(const GLchar* name, float value);
			void setUniform1i(const GLchar* name, int value);
			void setUniform2f(const GLchar* name, const maths::vec2& vector);
			void setUniform3f(const GLchar* name, const maths::vec3& vector);
			void setUniform4f(const GLchar* name, const maths::vec4& vector);
			void setUniformMat4(const GLchar* name, const maths::mat4& matrix);

		private:
			GLuint load();
			GLint getUniformLocation(const GLchar* name);
		};

	}
}