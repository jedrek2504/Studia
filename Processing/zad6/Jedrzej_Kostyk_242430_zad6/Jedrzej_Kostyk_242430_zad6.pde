// obj file (Rocket.obj) source: https://www.cgtrader.com/free-3d-models/vehicle/sci-fi/hoverbike-the-rocket
import peasy.*;

PeasyCam Cam;  // PeasyCam object for easy camera manipulation
float time = 0.0f;  // Time variable
float vectorX = 0;  // X component of position vector
float vectorY = 100;  // Y component of position vector
float vectorZ = 500;  // Z component of position vector
float rspeed = 0.0187;  // Rotation speed
float vspeed = 1.87;  // Velocity speed
float pspeed = 1.2;  // Rocket rotation speed
PShape wczyt_bryla;  // Shape object for capsule.obj
PShape Rocket;  // Shape object for TheRocket.obj
boolean Forward, Backward, Up, Down, Left, Right, RXp, RXm, RYp, RYm, RZp, RZm, Spin, RSpin;  // Boolean variables for key states
float rotX = -3.2;  // X rotation angle
float rotY, rotZ;  // Y and Z rotation angles

void setup() {
  noStroke();
  fullScreen(P3D);  // Set up a full-screen P3D rendering
  wczyt_bryla = loadShape("capsule.obj");  // Load the capsule.obj shape
  Rocket = loadShape("TheRocket.obj");  // Load the TheRocket.obj shape
  Cam = new PeasyCam(this, 1000);  // Create a new PeasyCam object
}

void draw() {
  background(0);
  lights();

  // Render the sun
  pushMatrix();
  pointLight(230, 92, 0, 0, 0, 0);
  specular(#E65C00);
  emissive(#E65C00);
  sphere(50);
  emissive(0, 0, 0);
  popMatrix();

  // Render p1
  pushMatrix();
  rotateX(time * 1.7f);
  spotLight(0, 0, 255, 0, 0, 0, 0, 1, 0, 90, 1);
  translate(0, 0, 120.f);
  specular(#747b81);
  fill(#747b81);
  pushMatrix();
  rotateZ(time * 1.7f);
  box(30);
  popMatrix();

  // Render m1
  pushMatrix();
  rotateY(time * 1.f);
  translate(50, 0);
  fill(#25587C);
  sphere(10);
  popMatrix();

  // Render m2
  pushMatrix();
  rotateY(time * 3.1f);
  translate(70, 0);
  fill(#F4F4F4);
  sphere(7);
  popMatrix();

  popMatrix();

  // Render p2
  pushMatrix();
  rotateY(time * 0.7f);
  translate(0, 0, 230.f);
  specular(#968396);
  fill(#968396);
  sphere(30);

  // Render m3
  pushMatrix();
  rotateZ(time * 7.f);
  translate(45, 0);
  fill(#CACACA);
  sphere(7);
  popMatrix();

  popMatrix();

  // Render p3
  pushMatrix();
  rotateY(time * 2.1f);
  translate(0, 0, 350.f);
  specular(#8CB1DE);
  fill(#8CB1DE);
  pushMatrix();
  rotateX(time * 2.1f);
  scale(30);
  shape(wczyt_bryla);
  popMatrix();

  // Render m4
  pushMatrix();
  rotateZ(time * 3.f);
  translate(60, 0);
  fill(#FEFCD7);
  sphere(5);
  popMatrix();

  popMatrix();

  // Render p4
  pushMatrix();
  rotateY(time * pspeed);
  translate(0, 0, 500.f);
  specular(#9C2E35);
  fill(#9C2E35);
  sphere(30);

  // Render m5
  pushMatrix();
  rotate(time * 3.9f);
  translate(45, 0);
  fill(#122F50);
  sphere(7);
  popMatrix();

  // Render m6
  pushMatrix();
  rotate(time * 2.2f);
  translate(65, 0);
  fill(#3AA8C2);
  sphere(10);
  popMatrix();

  // Render m7
  pushMatrix();
  rotate(time * 1.6f);
  translate(90, 0);
  fill(#CED0F5);
  sphere(13);
  popMatrix();

  popMatrix();

  // Render the rocket as a spaceship
  pushMatrix();
  translate(vectorX, vectorY, vectorZ);
  specular(#8CB1DE);
  fill(#8CB1DE);
  pushMatrix();
  rotateX(rotX);
  rotateY(rotY);
  rotateZ(rotZ);
  scale(15);
  shape(Rocket);
  popMatrix();

  popMatrix();

  time = time + .01f;

  // Update position and rotation based on key states
 // Update position and rotation based on key states
if (Forward || mouseButton == RIGHT) {
  // Move forward along the Z-axis
  vectorZ = vectorZ - vspeed;
} else if (Backward) {
  // Move backward along the Z-axis
  vectorZ = vectorZ + vspeed;
}

if (Up) {
  // Move upward along the Y-axis
  vectorY = vectorY - vspeed;
} else if (Down) {
  // Move downward along the Y-axis
  vectorY = vectorY + vspeed;
}

if (Right) {
  // Move right along the X-axis
  vectorX = vectorX + vspeed;
} else if (Left) {
  // Move left along the X-axis
  vectorX = vectorX - vspeed;
}

if (RXp) {
  // Rotate positively around the X-axis
  rotX = rotX + rspeed;
} else if (RXm) {
  // Rotate negatively around the X-axis
  rotX = rotX - rspeed;
}

if (RYp) {
  // Rotate positively around the Y-axis
  rotY = rotY + rspeed;
} else if (RYm) {
  // Rotate negatively around the Y-axis
  rotY = rotY - rspeed;
}

if (RZp) {
  // Rotate positively around the Z-axis
  rotZ = rotZ + rspeed;
} else if (RZm) {
  // Rotate negatively around the Z-axis
  rotZ = rotZ - rspeed;
}

}

// Function to handle key press events
void pressKey(char sign) {
  switch (sign) {
    case 'W':
      // Set the forward key state to true
      Forward = true;
      break;
    case 'S':
      // Set the backward key state to true
      Backward = true;
      break;
    case 'Z':
      // Set the up key state to true
      Up = true;
      break;
    case 'X':
      // Set the down key state to true
      Down = true;
      break;
    case 'A':
      // Set the left key state to true
      Left = true;
      break;
    case 'D':
      // Set the right key state to true
      Right = true;
      break;
    case '8':
      // Set the positive X rotation key state to true
      RXp = true;
      break;
    case '9':
      // Set the positive Y rotation key state to true
      RYp = true;
      break;
    case '0':
      // Set the positive Z rotation key state to true
      RZp = true;
      break;
    case 'I':
      // Set the negative X rotation key state to true
      RXm = true;
      break;
    case 'O':
      // Set the negative Y rotation key state to true
      RYm = true;
      break;
    case 'P':
      // Set the negative Z rotation key state to true
      RZm = true;
      break;
  }
}

// Function to handle key release events
void releaseKey(char sign) {
  switch (sign) {
    case 'W':
      // Set the forward key state to false
      Forward = false;
      break;
    case 'S':
      // Set the backward key state to false
      Backward = false;
      break;
    case 'Z':
      // Set the up key state to false
      Up = false;
      break;
    case 'X':
      // Set the down key state to false
      Down = false;
      break;
    case 'A':
      // Set the left key state to false
      Left = false;
      break;
    case 'D':
      // Set the right key state to false
      Right = false;
      break;
    case '8':
      // Set the positive X rotation key state to false
      RXp = false;
      break;
    case '9':
      // Set the positive Y rotation key state to false
      RYp = false;
      break;
    case '0':
      // Set the positive Z rotation key state to false
      RZp = false;
      break;
    case 'I':
      // Set the negative X rotation key state to false
      RXm = false;
      break;
    case 'O':
      // Set the negative Y rotation key state to false
      RYm = false;
      break;
    case 'P':
      // Set the negative Z rotation key state to false
      RZm = false;
      break;
  }
}


// Event handler for key press events
void keyPressed() {
  if (keyCode == 'W') {
    // Call pressKey() with the key sign 'W'
    pressKey('W');
  } else if (keyCode == 'S') {
    // Call pressKey() with the key sign 'S'
    pressKey('S');
  } else if (keyCode == 'A') {
    // Call pressKey() with the key sign 'A'
    pressKey('A');
  } else if (keyCode == 'D') {
    // Call pressKey() with the key sign 'D'
    pressKey('D');
  } else if (keyCode == 'Z') {
    // Call pressKey() with the key sign 'Z'
    pressKey('Z');
  } else if (keyCode == 'X') {
    // Call pressKey() with the key sign 'X'
    pressKey('X');
  } else if (keyCode == '8') {
    // Call pressKey() with the key sign '8'
    pressKey('8');
  } else if (keyCode == '9') {
    // Call pressKey() with the key sign '9'
    pressKey('9');
  } else if (keyCode == '0') {
    // Call pressKey() with the key sign '0'
    pressKey('0');
  } else if (keyCode == 'I') {
    // Call pressKey() with the key sign 'I'
    pressKey('I');
  } else if (keyCode == 'O') {
    // Call pressKey() with the key sign 'O'
    pressKey('O');
  } else if (keyCode == 'P') {
    // Call pressKey() with the key sign 'P'
    pressKey('P');
  } else if (keyCode == 'M') {
    // Increase the pspeed variable by 0.3
    pspeed = pspeed + 0.3f;
  } else if (keyCode == 'N') {
    // Decrease the pspeed variable by 0.3
    pspeed = pspeed - 0.3f;
  }
}


// Event handler for key release events
void keyReleased() {
  if (keyCode == 'W') {
    // Call releaseKey() with the key sign 'W'
    releaseKey('W');
  } else if (keyCode == 'S') {
    // Call releaseKey() with the key sign 'S'
    releaseKey('S');
  } else if (keyCode == 'A') {
    // Call releaseKey() with the key sign 'A'
    releaseKey('A');
  } else if (keyCode == 'D') {
    // Call releaseKey() with the key sign 'D'
    releaseKey('D');
  } else if (keyCode == 'Z') {
    // Call releaseKey() with the key sign 'Z'
    releaseKey('Z');
  } else if (keyCode == 'X') {
    // Call releaseKey() with the key sign 'X'
    releaseKey('X');
  } else if (keyCode == '8') {
    // Call releaseKey() with the key sign '8'
    releaseKey('8');
  } else if (keyCode == '9') {
    // Call releaseKey() with the key sign '9'
    releaseKey('9');
  } else if (keyCode == '0') {
    // Call releaseKey() with the key sign '0'
    releaseKey('0');
  } else if (keyCode == 'I') {
    // Call releaseKey() with the key sign 'I'
    releaseKey('I');
  } else if (keyCode == 'O') {
    // Call releaseKey() with the key sign 'O'
    releaseKey('O');
  } else if (keyCode == 'P') {
    // Call releaseKey() with the key sign 'P'
    releaseKey('P');
  }
}
