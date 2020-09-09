#pragma once

#include <render/shader.h>

namespace Undead
{
	namespace Render
	{

		enum Material
		{
			DEFAULT,
			EMERALD, 
			JADE, 
			OBSIDIAN, 
			PEARL, 
			RUBY, 
			TURQUOISE,
			BRASS,
			BRONZE,
			CHROME,
			COPPER,
			GOLD,
			SILVER,
			BLACK_PLASTIC,
			CYAN_PLASTIC,
			GREEN_PLASTIC,
			RED_PLASTIC,
			WHITE_PLASTIC,
			YELLOW_PLASTIC,
			BLACK_RUBBER,
			CYAN_RUBBER,
			GREEN_RUBBER,
			RED_RUBBER,
			WHITE_RUBBER,
			YELLOW_RUBBER
		};
		class Light
		{
		private:
			int materialID;
		public:
			Light(Material material = DEFAULT);
			void setupLightPositions(Shader& shader, glm::vec3& viewPos, glm::vec3& lightPos);
			void setupMaterial(Shader& shader);
			void setupLighting(Shader& shader);
		};
	}
}