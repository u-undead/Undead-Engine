#include "light.h"

namespace Undead
{
	namespace Render
	{
		Light::Light(Material material)
		{
			materialID = material;
		}

		void Light::setupLightPositions(Shader& shader, glm::vec3& viewPos, glm::vec3& lightPos)
		{
			shader.setVec3("light.position", lightPos);
			shader.setVec3("viewPos", viewPos);
		}

		void Light::setupMaterial(Shader& shader)
		{
			switch (materialID)
			{
			case DEFAULT:
				shader.setVec3("material.ambient", 1.0f, 1.0f, 1.0f);
				shader.setVec3("material.diffuse", 1.0f, 1.0f, 1.0f);
				shader.setVec3("material.specular", 0.5f, 0.5f, 0.5f);
				shader.setFloat("material.shininess", 32.0f);
				break;
			case EMERALD:
				shader.setVec3("material.ambient", 0.0215, 0.1745, 0.0215);
				shader.setVec3("material.diffuse", 0.07568, 0.61424, 0.07568);
				shader.setVec3("material.specular", 0.633, 0.727811, 0.633);
				shader.setFloat("material.shininess", 0.6 * 128);
				break;
			case JADE:
				shader.setVec3("material.ambient", 0.135, 0.2225, 0.1575);
				shader.setVec3("material.diffuse", 0.54, 0.89, 0.63);
				shader.setVec3("material.specular", 0.316228, 0.316228, 0.316228);
				shader.setFloat("material.shininess", 0.1 * 128);
				break;
			case OBSIDIAN:
				shader.setVec3("material.ambient", 0.05375, 0.05, 0.06625);
				shader.setVec3("material.diffuse", 0.18275, 0.17, 0.22525);
				shader.setVec3("material.specular", 0.332741, 0.328634, 0.346435);
				shader.setFloat("material.shininess", 0.3 * 128);
				break;
			case PEARL:
				shader.setVec3("material.ambient", 0.25, 0.20725, 0.20725);
				shader.setVec3("material.diffuse", 1, 0.829, 0.829);
				shader.setVec3("material.specular", 0.296648, 0.296648, 0.296648);
				shader.setFloat("material.shininess", 0.088 * 128);
				break;
			case RUBY:
				shader.setVec3("material.ambient", 0.1745, 0.01175, 0.01175);
				shader.setVec3("material.diffuse", 0.61424, 0.04136, 0.04136);
				shader.setVec3("material.specular", 0.727811, 0.626959, 0.626959);
				shader.setFloat("material.shininess", 0.6 * 128);
				break;
			case TURQUOISE:
				shader.setVec3("material.ambient", 0.1, 0.18725, 0.1745);
				shader.setVec3("material.diffuse", 0.396, 0.74151, 0.69102);
				shader.setVec3("material.specular", 0.297254, 0.30829, 0.306678);
				shader.setFloat("material.shininess", 0.1 * 128);
				break;
			case BRASS:
				shader.setVec3("material.ambient", 0.1, 0.18725, 0.1745);
				shader.setVec3("material.diffuse", 0.396, 0.74151, 0.69102);
				shader.setVec3("material.specular", 0.297254, 0.30829, 0.306678);
				shader.setFloat("material.shininess", 0.21794872 * 128);
				break;
			case BRONZE:
				shader.setVec3("material.ambient", 0.2125, 0.1275, 0.054);
				shader.setVec3("material.diffuse", 0.714, 0.4284, 0.18144);
				shader.setVec3("material.specular", 0.393548, 0.271906, 0.166721);
				shader.setFloat("material.shininess", 0.2 * 128);
				break;
			case CHROME:
				shader.setVec3("material.ambient", 0.25, 0.25, 0.25);
				shader.setVec3("material.diffuse", 0.4, 0.4, 0.4);
				shader.setVec3("material.specular", 0.774597, 0.774597, 0.774597);
				shader.setFloat("material.shininess", 0.6 * 128);
				break;
			case COPPER:
				shader.setVec3("material.ambient",  0.19125,  0.0735,   0.0225);
				shader.setVec3("material.diffuse",  0.7038,   0.27048,  0.0828);
				shader.setVec3("material.specular", 0.256777, 0.137622, 0.086014);
				shader.setFloat("material.shininess", 0.1 * 128);
				break;
			case GOLD:
				shader.setVec3("material.ambient",  0.24725,  0.1995,   0.0745);
				shader.setVec3("material.diffuse",  0.75164,  0.60648,  0.22648);
				shader.setVec3("material.specular", 0.628281, 0.555802, 0.366065);
				shader.setFloat("material.shininess", 0.4 * 128);
				break;
			case SILVER:
				shader.setVec3("material.ambient",  0.19225,  0.19225,  0.19225);
				shader.setVec3("material.diffuse",  0.50754,  0.50754,  0.50754);
				shader.setVec3("material.specular", 0.508273, 0.508273, 0.508273);
				shader.setFloat("material.shininess", 0.4 * 128);
				break;
			case BLACK_PLASTIC:
				shader.setVec3("material.ambient", 0, 0, 0);
				shader.setVec3("material.diffuse", 0.1, 0.1, 0.1);
				shader.setVec3("material.specular", 0.5, 0.5, 0.5);
				shader.setFloat("material.shininess", 0.25 * 128);
				break;
			case CYAN_PLASTIC:
				shader.setVec3("material.ambient", 0, 0.1, 0.6);
				shader.setVec3("material.diffuse", 0, 0.50980392, 0.50980392);
				shader.setVec3("material.specular", 0.50196078, 0.50196078, 0.50196078);
				shader.setFloat("material.shininess", 0.25 * 128);
				break;
			case GREEN_PLASTIC:
				shader.setVec3("material.ambient", 0.0, 0.0, 0.0);
				shader.setVec3("material.diffuse", 0.1, 0.35, 0.1);
				shader.setVec3("material.specular", 0.45, 0.55, 0.45);
				shader.setFloat("material.shininess", 0.25 * 128);
				break;
			case RED_PLASTIC:
				shader.setVec3("material.ambient", 0.0, 0.0, 0.0);
				shader.setVec3("material.diffuse", 0.5, 0.0, 0.0);
				shader.setVec3("material.specular", 0.7, 0.6, 0.6);
				shader.setFloat("material.shininess", 0.25 * 128);
				break;
			case WHITE_PLASTIC:
				shader.setVec3("material.ambient", 0.0, 0.0, 0.0);
				shader.setVec3("material.diffuse", 0.55, 0.55, 0.55);
				shader.setVec3("material.specular", 0.70, 0.70, 0.70);
				shader.setFloat("material.shininess", 0.25 * 128);
				break;
			case YELLOW_PLASTIC:
				shader.setVec3("material.ambient", 0.0, 0.0, 0.0);
				shader.setVec3("material.diffuse", 0.5, 0.5, 0.0);
				shader.setVec3("material.specular", 0.60, 0.60, 0.50);
				shader.setFloat("material.shininess", 0.25 * 128);
				break;
			case BLACK_RUBBER:
				shader.setVec3("material.ambient", 0.02, 0.02, 0.02);
				shader.setVec3("material.diffuse", 0.01, 0.01, 0.01);
				shader.setVec3("material.specular", 0.4, 0.4, 0.4);
				shader.setFloat("material.shininess", 0.078125 * 128);
				break;
			case CYAN_RUBBER:
				shader.setVec3("material.ambient", 0.0, 0.05, 0.05);
				shader.setVec3("material.diffuse", 0.4, 0.5, 0.5);
				shader.setVec3("material.specular", 0.04, 0.7, 0.7);
				shader.setFloat("material.shininess", 0.078125 * 128);
				break;
			case GREEN_RUBBER:
				shader.setVec3("material.ambient", 0.0, 0.05, 0.0);
				shader.setVec3("material.diffuse", 0.4, 0.5, 0.4);
				shader.setVec3("material.specular", 0.04, 0.7, 0.04);
				shader.setFloat("material.shininess", 0.078125 * 128);
				break;
			case RED_RUBBER:
				shader.setVec3("material.ambient", 0.05, 0.0, 0.0);
				shader.setVec3("material.diffuse", 0.5, 0.4, 0.4);
				shader.setVec3("material.specular", 0.7, 0.04, 0.04);
				shader.setFloat("material.shininess", 0.078125 * 128);
				break;
			case WHITE_RUBBER:
				shader.setVec3("material.ambient", 0.05, 0.05, 0.05);
				shader.setVec3("material.diffuse", 0.5, 0.5, 0.5);
				shader.setVec3("material.specular", 0.7, 0.7, 0.7);
				shader.setFloat("material.shininess", 0.078125 * 128);
				break;
			case YELLOW_RUBBER:
				shader.setVec3("material.ambient", 0.05, 0.05, 0.0);
				shader.setVec3("material.diffuse", 0.5, 0.5, 0.4);
				shader.setVec3("material.specular", 0.7, 0.7, 0.04);
				shader.setFloat("material.shininess", 0.078125 * 128);
				break;
			}
		}
		void Light::setupLighting(Shader& shader)
		{
			shader.setVec3("light.ambient", 0.2f, 0.2f, 0.2f);
			shader.setVec3("light.diffuse", 0.5f, 0.5f, 0.5f); // darken diffuse light a bit
			shader.setVec3("light.specular", 1.0f, 1.0f, 1.0f);
		}
	}
}