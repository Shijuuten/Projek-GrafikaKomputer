#include "Application.h"

Application::Application()
{
	angle = 0;
}

Application::~Application()
{
}

void Application::setupPerspective()
{
	// Pass perspective projection matrix
	glm::mat4 projection = glm::perspective(45.0f, (GLfloat)this->screenWidth / (GLfloat)this->screenHeight, 0.1f, 100.0f);
	shader->setMat4("projection", projection);
}

void Application::setupCamera()
{
	// LookAt camera (position, target/direction, up)
	viewPos = glm::vec3(-1, 2, 2);
	glm::mat4 view = glm::lookAt(viewPos, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	shader->setMat4("view", view);
}

void Application::setupLighting()
{
	// set lighting attributes
	glm::vec3 lightPos = glm::vec3( -5, 4, 5);
	shader->setVec3("lightPos", lightPos);
	shader->setVec3("viewPos", viewPos);
	glm::vec3 lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
	shader->setVec3("lightColor", lightColor);
}

void Application::Init()
{
	// Build a lighting map shader
	shader = new Shader("cube.vert", "cube.frag");
	shader->Init();
	// Create instance of cube
	cube = new Cube(shader);
	cube->Init();
	//cube->SetRotation(0, 0, 1, 0);
	
	// setup perspective 
	setupPerspective();
	// setup camera
	setupCamera();
	// setup lighting
	setupLighting();
}

void Application::DeInit()
{
	delete cube;
}

void Application::Update(double deltaTime)
{
	lastLightToggled += deltaTime;
	angle += (float)((deltaTime * 0.5f) / 1000);
	ProcessInput(this->window);

	//angle += (float)((deltaTime * 0.5f) / 1000);
	//cube->SetRotation(angle, 0, 1, 0);
}

void Application::Render()
{
	glViewport(0, 0, this->screenWidth, this->screenHeight);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	SetBackgroundColor(237, 234, 226);

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glEnable(GL_DEPTH_TEST);
	//Pintu WC Buka
	cube->SetColor(37.0f, 37.0f, 38.0f);
	cube->SetPosition(-5.24f, 0.8f, 1.36f);
	cube->SetScale(1.35f, 2.5f, 0.03f);
	cube->Draw();

	//Pintu WC Tutup
	for (int i = 0; i < 4; i++) {
		cube->SetColor(37.0f, 37.0f, 38.0f);
		cube->SetPosition(-4.6f, 0.8f, 2.8f + i * 2);
		cube->SetScale(0.03f, 2.5f, 1.15f);
		cube->Draw();
	}
	for (int i = 0; i < 5; i++) {
		//sensor urinoir

		cube->SetColor(37.0f, 37.0f, 38.0f);
		cube->SetPosition(-1.14f, 1.4f, 3.75f + i * 1.5);
		cube->SetScale(0.05f, 0.3f, 0.2f);
		cube->Draw();

		//Urinoir
		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-1.14f, 0.5f, 3.75f + i * 1.5);
		cube->SetScale(0.05f, 1.2f, 0.8f);
		cube->Draw();

		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-1.38f, 0.5f, 3.35f + i * 1.5);
		cube->SetScale(0.5f, 1.2f, 0.05f);
		cube->Draw();

		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-1.38f, 0.5f, 4.15f + i * 1.5);
		cube->SetScale(0.5f, 1.2f, 0.05f);
		cube->Draw();

		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-1.38f, 1.1f, 3.75f + i * 1.5);
		cube->SetScale(0.5f, 0.05f, 0.8f);
		cube->Draw();

		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-1.38f, -0.1f, 3.75f + i * 1.5);
		cube->SetScale(0.5f, 0.05f, 0.8f);
		cube->Draw();

		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-1.65f, 0.0f, 3.5f + i * 1.5);
		cube->SetScale(0.05f, 0.25f, 0.30f);
		cube->Draw();

		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-1.65f, 0.0f, 4.0f + i * 1.5);
		cube->SetScale(0.05f, 0.25f, 0.30f);
		cube->Draw();

		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-1.6f, -0.1f, 3.75f + i * 1.5);
		cube->SetScale(0.5f, 0.05f, 0.2f);
		cube->Draw();

		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-1.75f, 0.0f, 3.67f + i * 1.5);
		cube->SetScale(0.2f, 0.25f, 0.05f);
		cube->Draw();

		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-1.75f, 0.0f, 3.85f + i * 1.5);
		cube->SetScale(0.2f, 0.25f, 0.05f);
		cube->Draw();

		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-1.85f, 0.0f, 3.75f + i * 1.5);
		cube->SetScale(0.05f, 0.25f, 0.2f);
		cube->Draw();
	}


	for (int i = 0; i < 5; i++) {
		//Pembatas wc
		cube->SetColor(37.0f, 37.0f, 38.0f);
		cube->SetPosition(-6.0f, 0.8f, 1.8f + i * 2);
		cube->SetScale(2.8f, 2.5f, 0.03f);
		cube->Draw();

		cube->SetColor(37.0f, 37.0f, 38.0f);
		cube->SetPosition(-4.6f, 0.8f, 1.8f + i * 2);
		cube->SetScale(0.03f, 2.5f, 0.8f);
		cube->Draw();

		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-4.6f, 1.8f, 1.4f + i * 2);
		cube->SetScale(0.05f, 0.2f, 0.1f);
		cube->Draw();

		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-4.6f, -0.1f, 1.4f + i * 2);
		cube->SetScale(0.05f, 0.2f, 0.1f);
		cube->Draw();

		// Penyangga Lantai 1
		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-4.6f, -0.5f, 1.5f + i * 2);
		cube->SetScale(0.05f, 0.30f, 0.05f);
		cube->Draw();

		// Kaki Penyangga Lantai 1
		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-4.6f, -0.65f, 1.5f + i * 2);
		cube->SetScale(0.1f, 0.05f, 0.1f);
		cube->Draw();

		// Penyangga Lantai 2
		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-4.6f, -0.5f, 2.1f + i * 2);
		cube->SetScale(0.05f, 0.30f, 0.05f);
		cube->Draw();

		// Kaki Penyangga Lantai 2
		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-4.6f, -0.65f, 2.1f + i * 2);
		cube->SetScale(0.1f, 0.05f, 0.1f);
		cube->Draw();
	}
	
	cube->SetColor(37.0f, 37.0f, 38.0f);
	cube->SetPosition(-4.6f, 0.8f, -0.2f);
	cube->SetScale(0.03f, 2.5f, 0.4f);
	cube->Draw();

	//Atap
	cube->SetColor(216.0f, 186.0f, 137.0f);
	cube->SetPosition(-3.5f, 4.2f, 5.0f);
	cube->SetScale(8.0f, 0.2f, 10.9f);
	cube->Draw();

	//TembokX
	cube->SetColor(216.0f, 186.0f, 137.0f);
	cube->SetPosition(-3.5f, 1.7f, -0.49f);
	cube->SetScale(8.0f, 5.0f, 0.2f);
	cube->Draw();
	//TembokZ
	cube->SetColor(216.0f, 186.0f, 137.0f);
	cube->SetPosition(0.6f, 1.7f, 1.3f);
	cube->SetScale(0.2f, 5.0f, 3.4f);
	cube->Draw();
	//TembokX
	cube->SetColor(216.0f, 186.0f, 137.0f);
	cube->SetPosition(-4.18f, 1.7f, 10.3f);
	cube->SetScale(6.5f, 5.0f, 0.2f);
	cube->Draw();
	//TembokY
	cube->SetColor(216.0f, 186.0f, 137.0f);
	cube->SetPosition(-1.0f, 1.7f, 6.7f);
	cube->SetScale(0.2f, 5.0f, 7.0f);
	cube->Draw();
	//TembokX
	cube->SetColor(216.0f, 186.0f, 137.0f);
	cube->SetPosition(-0.8f, 1.7f, 3.1f);
	cube->SetScale(3.0f, 5.0f, 0.2f);
	cube->Draw();
	//TembokY
	for (int i = 0; i < 5; i++) {
		cube->SetColor(216.0f, 186.0f, 137.0f);
		cube->SetPosition(-7.5f, 1.7f, 0.7f + i * 2);
		cube->SetScale(0.2f, 5.0f, 3.0f);
		cube->Draw();
	}



	//Lantai
	for (int i = 0; i < 4; i++) {
		cube->SetColor(214.0f, 181.0f, 117.0f);
		cube->SetPosition(-7.0f +i * 2, -0.7f, 0.1f);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();

		cube->SetColor(94.0f, 62.0f, 23.0f);
		cube->SetPosition(-6.0f + i * 2, -0.7f, 0.1f);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();
	}

	for (int i = 0; i < 4; i++) {
		cube->SetColor(94.0f, 62.0f, 23.0f);
		cube->SetPosition(-7.0f + i * 2, -0.7f, 1.1f);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();

		cube->SetColor(214.0f, 181.0f, 117.0f);
		cube->SetPosition(-6.0f + i * 2, -0.7f, 1.1f);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();
	}

	for (int i = 0; i < 4; i++) {
		cube->SetColor(214.0f, 181.0f, 117.0f);
		cube->SetPosition(-7.0f + i * 2, -0.7f, 2.1f);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();

		cube->SetColor(94.0f, 62.0f, 23.0f);
		cube->SetPosition(-6.0f + i * 2, -0.7f, 2.1f);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();
	}

	for (int i = 0; i < 4; i++) {
		cube->SetColor(94.0f, 62.0f, 23.0f);
		cube->SetPosition(-7.0f + i * 2, -0.7f, 3.1f);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();

		cube->SetColor(214.0f, 181.0f, 117.0f);
		cube->SetPosition(-6.0f + i * 2, -0.7f, 3.1f);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();
	}
	for (int i = 0; i < 4; i++) {
		cube->SetColor(214.0f, 181.0f, 117.0f);
		cube->SetPosition(-7.0f, -0.7f, 4.1f + i * 2);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();

		cube->SetColor(94.0f, 62.0f, 23.0f);
		cube->SetPosition(-7.0f, -0.7f, 5.1f + i * 2);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();
	}

	for (int i = 0; i < 4; i++) {
		cube->SetColor(94.0f, 62.0f, 23.0f);
		cube->SetPosition(-6.0f, -0.7f, 4.1f + i * 2);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();

		cube->SetColor(214.0f, 181.0f, 117.0f);
		cube->SetPosition(-6.0f, -0.7f, 5.1f + i * 2);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();
	}
	for (int i = 0; i < 4; i++) {
		cube->SetColor(214.0f, 181.0f, 117.0f);
		cube->SetPosition(-5.0f, -0.7f, 4.1f + i * 2);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();

		cube->SetColor(94.0f, 62.0f, 23.0f);
		cube->SetPosition(-5.0f, -0.7f, 5.1f + i * 2);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();
	}
	for (int i = 0; i < 4; i++) {
		cube->SetColor(94.0f, 62.0f, 23.0f);
		cube->SetPosition(-4.0f, -0.7f, 4.1f + i * 2);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();

		cube->SetColor(214.0f, 181.0f, 117.0f);
		cube->SetPosition(-4.0f, -0.7f, 5.1f + i * 2);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();
	}
	for (int i = 0; i < 4; i++) {
		cube->SetColor(214.0f, 181.0f, 117.0f);
		cube->SetPosition(-3.0f, -0.7f, 4.1f + i * 2);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();

		cube->SetColor(94.0f, 62.0f, 23.0f);
		cube->SetPosition(-3.0f, -0.7f, 5.1f + i * 2);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();
	}
	for (int i = 0; i < 4; i++) {
		cube->SetColor(94.0f, 62.0f, 23.0f);
		cube->SetPosition(-2.0f, -0.7f, 4.1f + i * 2);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();

		cube->SetColor(214.0f, 181.0f, 117.0f);
		cube->SetPosition(-2.0f, -0.7f, 5.1f + i * 2);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();
	}
	for (int i = 0; i < 4; i++) {
		cube->SetColor(214.0f, 181.0f, 117.0f);
		cube->SetPosition(-1.0f, -0.7f, 4.1f + i * 2);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();

		cube->SetColor(94.0f, 62.0f, 23.0f);
		cube->SetPosition(-1.0f, -0.7f, 5.1f + i * 2);
		cube->SetScale(1.0f, 0.1f, 1.0f);
		cube->Draw();
	}
	for (int i = 0; i < 2; i++) {
		//  Sabun
		// Tombol Sabun
		cube->SetColor(128.0f, 128.0f, 128.0f);
		cube->SetPosition(-1.5f + i, 1.2f, -0.25f);
		cube->SetScale(0.025f, 0.025f, 0.01f);
		cube->Draw();

		// Sabun
		cube->SetColor(220.0f, 220.0f, 220.0f);
		cube->SetPosition(-1.5f + i, 1.2f, -0.35f);
		cube->SetScale(0.16f, 0.3f, 0.2f);
		cube->Draw();
	}
	//Wastafel
	for (int i = 0; i < 3; i++) {
		cube->SetColor(255.0f, 255.0f, 255.0f);
		cube->SetPosition(-2.0f + i, 0.8f, 0.01f);
		cube->SetScale(0.7f, 0.1f, 0.6f);
		cube->Draw();

		//Kaca Wastafel
		cube->SetColor(224.0f, 224.0f, 224.0f);
		cube->SetPosition(-2.0f + i, 2.2f, -0.35f);
		cube->SetScale(0.8f, 2.5f, 0.03f);
		cube->Draw();
	}

	for (int i = 0; i < 3; i++) {
		//Keran Kotak 2
		cube->SetColor(128.0f, 128.0f, 128.0f);
		cube->SetPosition(-2.0f + i, 1.05f, -0.13f);
		cube->SetScale(0.1f, 0.05f, 0.2f);
		cube->Draw();
		//Keran Kotak 1
		cube->SetColor(128.0f, 128.0f, 128.0f);
		cube->SetPosition(-2.0f + i, 0.8f, -0.20f);
		cube->SetScale(0.1f, 0.5f, 0.05f);
		cube->Draw();
	}

	//Kotak belakang keran
	cube->SetColor(1.0f, 1.0f, 1.0f);
	cube->SetPosition(-1.0f, 0.8f, -0.35f);
	cube->SetScale(3.0f, 0.2f, 0.08f);
	cube->Draw();
	//Badan Wastafel
	cube->SetColor(1.0f, 1.0f, 1.0f);
	cube->SetPosition(-1.0f, 0.3f, 0.01f);
	cube->SetScale(3.0f, 1.0f, 0.8f);
	cube->Draw();

	for (int i = 0; i < 4; i++) {
		//Pembatas Urinal
	// Kaca Pembatas
		cube->SetColor(220.0f, 220.0f, 220.0f);
		cube->SetPosition(-1.65f, 0.25f, 4.45f + i * 1.5);
		cube->SetScale(1.0f, 1.2f, 0.03f);
		cube->Draw();

		// Penyangga Tembok Pembatas
		cube->SetColor(51.0f, 51.0f, 51.0f);
		cube->SetPosition(-1.14f, -0.05f, 4.45f + i * 1.5);
		cube->SetScale(0.1f, 0.075f, 0.04f);
		cube->Draw();

		cube->SetColor(51.0f, 51.0f, 51.0f);
		cube->SetPosition(-1.14f, 0.55f, 4.45f + i * 1.5);
		cube->SetScale(0.1f, 0.075f, 0.04f);
		cube->Draw();

		// Penyangga Lantai Pembatas
		cube->SetColor(51.0f, 51.0f, 51.0f);
		cube->SetPosition(-1.85f, -0.45f, 4.45f + i * 1.5);
		cube->SetScale(0.05f, 0.30f, 0.05f);
		cube->Draw();

		// Kaki Penyangga Lantai Pembatas
		cube->SetColor(51.0f, 51.0f, 51.0f);
		cube->SetPosition(-1.85f, -0.62f, 4.45f + i * 1.5);
		cube->SetScale(0.1f, 0.05f, 0.1f);
		cube->Draw();
	}
	

	for (int i = 0; i < 5; i++) {
		//Jamban 

	// Badan
		cube->SetColor(220.0f, 220.0f, 220.0f);
		cube->SetPosition(-6.4f, 0.0f, 0.7f + i * 2);
		cube->SetScale(0.8f, 0.3f, 0.8f);
		cube->Draw();

		// Tutup
		cube->SetColor(220.0f, 220.0f, 220.0f);
		cube->SetPosition(-6.4f, 0.23f, 0.7f + i * 2);
		cube->SetScale(0.8f, 0.1f, 0.8f);
		cube->Draw();

		// Kaki
		cube->SetColor(220.0f, 220.0f, 220.0f);
		cube->SetPosition(-6.7f, -0.4f, 0.7f + i * 2);
		cube->SetScale(0.8f, 0.7f, 0.1f);
		cube->Draw();

		cube->SetColor(220.0f, 220.0f, 220.0f);
		cube->SetPosition(-6.7f, -0.4f, 0.6f + i * 2);
		cube->SetScale(0.6f, 0.7f, 0.1f);
		cube->Draw();

		cube->SetColor(220.0f, 220.0f, 220.0f);
		cube->SetPosition(-6.7f, -0.4f, 0.8f + i * 2);
		cube->SetScale(0.4f, 0.7f, 0.1f);
		cube->Draw();

		cube->SetColor(220.0f, 220.0f, 220.0f);
		cube->SetPosition(-6.7f, -0.4f, 0.5f + i * 2);
		cube->SetScale(0.4f, 0.7f, 0.1f);
		cube->Draw();

		cube->SetColor(220.0f, 220.0f, 220.0f);
		cube->SetPosition(-6.7f, -0.4f, 0.9f + i * 2);
		cube->SetScale(0.4f, 0.7f, 0.1f);
		cube->Draw();

		// Tangki Air
		cube->SetColor(220.0f, 220.0f, 220.0f);
		cube->SetPosition(-6.9f, 0.3f, 0.7f + i * 2);
		cube->SetScale(0.2f, 0.7f, 0.8);
		cube->Draw();

		// Flush
		cube->SetColor(128.0f, 128.0f, 128.0f);
		cube->SetPosition(-6.9f, 0.65f, 0.7f + i * 2);
		cube->SetScale(0.07f, 0.025f, 0.08f);
		cube->Draw();

		cube->SetColor(128.0f, 128.0f, 128.0f);
		cube->SetPosition(-6.9f, 0.66f, 0.69f + i * 2);
		cube->SetScale(0.05f, 0.025f, -0.03f);
		cube->Draw();
	}

	

	glDisable(GL_DEPTH_TEST);

}

void Application::UpdateCameraDirection(double xpos, double ypos)
{
	// Update yaw dan pitch berdasarkan input mouse
	yaw += xpos;
	pitch += ypos;

	// Batasi pitch agar tidak melebihi batas atas dan bawah
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	// Hitung vektor arah kamera berdasarkan yaw dan pitch
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

	// Normalisasi vektor arah kamera
	viewDir = glm::normalize(front);

	// Perbarui matriks pandangan (view matrix)
	glm::mat4 view = glm::lookAt(viewPos, viewPos + viewDir, glm::vec3(0, 1, 0));
	shader->setMat4("view", view);
}


void Application::ProcessInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	double xpos, ypos;
	glfwGetCursorPos(window, &xpos, &ypos);

	if (firstMouse) {
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos;
	lastX = xpos;
	lastY = ypos;

	// Faktor sensitivitas mouse
	float sensitivity = 0.5f;
	xoffset *= sensitivity;
	yoffset *= sensitivity;

	// Update orientasi kamera berdasarkan input mouse
	UpdateCameraDirection(xoffset, yoffset);

	// Fixed camera movement speed
	float fixedMovementSpeed = 0.001f;

	// Update camera position based on keyboard input
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		viewPos += fixedMovementSpeed * viewDir;

	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		viewPos -= fixedMovementSpeed * viewDir;

	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		viewPos -= glm::normalize(glm::cross(viewDir, glm::vec3(0.0f, 1.0f, 0.0f))) * fixedMovementSpeed;

	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		viewPos += glm::normalize(glm::cross(viewDir, glm::vec3(0.0f, 1.0f, 0.0f))) * fixedMovementSpeed;


	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && lastLightToggled > 200) {
		lampOn = !lampOn;
		lastLightToggled = 0;
	}

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && lastLightToggled > 200) {
		skyOn = !skyOn;
		lastLightToggled = 0;
	}
}



int main(int argc, char** argv) {
	Application app = Application();
	app.Start("Cube Example", 
		1366, 768, 
		false, 
		false);
}