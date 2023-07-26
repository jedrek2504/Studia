float time = 0.0f;  // Variable to keep track of time
//PImage background;
PShape wczyt_bryla;  // Variable to store a 3D shape

void setup() {
  noStroke();
  fullScreen(P3D);  // Set up the sketch to run in full screen with 3D rendering
  //background = loadImage("bg6.jpg");  // Load an image for the background (commented out)
  wczyt_bryla = loadShape("capsule.obj");  // Load a 3D shape from an OBJ file
}

void draw() {
  background(0);  // Set the background color to black
  //image(background, 0, 0);  // Display the background image (commented out)
  translate(width * 0.5f, height * 0.5f);  // Translate the coordinate system to the center of the screen
  lights();  // Enable lighting

  // Sun
  pushMatrix();
  pointLight(230, 92, 0, 0, 0, 0);  // Add a point light source with orange color
  specular(#E65C00);  // Set the specular reflection color to orange
  emissive(#E65C00);  // Set the emissive (glowing) color to orange
  sphere(50);  // Draw a sphere for the sun
  emissive(0, 0, 0);  // Reset the emissive color to black
  popMatrix();

  // Planet 1
  pushMatrix();
  rotateX(time * 1.7f);  // Rotate the planet around the x-axis based on time
  //spotLight(0, 0, 255, 0, 0, 0, 0, 1, 0, 90, 1);  // Add a spot light with blue color
  translate(0, 0, 120.f);  // Translate to the position of planet 1
  specular(#747b81);  // Set the specular reflection color to gray
  fill(#747b81);  // Set the fill color to gray
  pushMatrix();
  rotateZ(time * 1.7f);  // Rotate the moon around the z-axis based on time
  box(30);  // Draw a box for the moon
  popMatrix();
  
  // Moon 1
  pushMatrix();
  rotateY(time * 1.f);  // Rotate the moon around the y-axis based on time
  translate(50, 0);  // Translate to the position of moon 1
  fill(#25587C);  // Set the fill color to dark blue
  sphere(10);  // Draw a sphere for the moon
  popMatrix();
  
  // Moon 2
  pushMatrix();
  rotateY(time * 3.1f);  // Rotate the moon around the y-axis based on time
  translate(70, 0);  // Translate to the position of moon 2
  fill(#F4F4F4);  // Set the fill color to light gray
  sphere(7);  // Draw a sphere for the moon
  popMatrix();
  
  popMatrix();

  // Planet 2
  pushMatrix();
  rotateY(time * 0.7f);  // Rotate the planet around the y-axis based on time
  translate(0, 0, 230.f);  // Translate to the position of planet 2
  specular(#968396);  // Set the specular reflection color to purple
  fill(#968396);  // Set the fill color to purple
  sphere(30);  // Draw a sphere for planet 2
  
  // Moon 3
  pushMatrix();
  rotateZ(time * 7.f);  // Rotate the moon around the z-axis based on time
  translate(45, 0);  // Translate to the position of moon 3
  fill(#CACACA);  // Set the fill color to light gray
  sphere(7);  // Draw a sphere for moon 3
  popMatrix();
  
  popMatrix();

  // Planet 3
  pushMatrix();
  rotateY(time * 2.1f);  // Rotate the planet around the y-axis based on time
  translate(0, 0, 350.f);  // Translate to the position of planet 3
  specular(#8CB1DE);  // Set the specular reflection color to light blue
  fill(#8CB1DE);  // Set the fill color to light blue
  pushMatrix();
  rotateX(time * 2.1f);  // Rotate the planet around the x-axis based on time
  scale(30);  // Scale the shape
  shape(wczyt_bryla);  // Draw the loaded 3D shape
  popMatrix();
  
  // Moon 4
  pushMatrix();
  rotateZ(time * 3.f);  // Rotate the moon around the z-axis based on time
  translate(60, 0);  // Translate to the position of moon 4
  fill(#FEFCD7);  // Set the fill color to light yellow
  sphere(5);  // Draw a sphere for moon 4
 // additional moon
  pushMatrix();
  rotate(time * 1.8f);  // Rotate the moon around the y-axis based on time
  translate(65, 0);  // Translate to the position of moon 1
  fill(#FFA500);  // Set the fill color to orange
  sphere(3);  // Draw a sphere for the moon
  popMatrix();
  
  popMatrix();
  
  
  
  popMatrix();

  // Planet 4
  pushMatrix();
  rotateY(time * 1.2f);  // Rotate the planet around the y-axis based on time
  translate(0, 0, 500.f);  // Translate to the position of planet 4
  specular(#9C2E35);  // Set the specular reflection color to dark red
  fill(#9C2E35);  // Set the fill color to dark red
  sphere(30);  // Draw a sphere for planet 4
  
  // Moon 5
  pushMatrix();
  rotate(time * 3.9f);  // Rotate the moon around itself based on time
  translate(45, 0);  // Translate to the position of moon 5
  fill(#122F50);  // Set the fill color to dark blue
  sphere(7);  // Draw a sphere for moon 5
  popMatrix();
  
  // Moon 6
  pushMatrix();
  rotate(time * 2.2f);  // Rotate the moon around itself based on time
  translate(65, 0);  // Translate to the position of moon 6
  fill(#3AA8C2);  // Set the fill color to turquoise
  sphere(10);  // Draw a sphere for moon 6
  popMatrix();
  
  // Moon 7
  pushMatrix();
  rotate(time * 1.6f);  // Rotate the moon around itself based on time
  translate(90, 0);  // Translate to the position of moon 7
  fill(#CED0F5);  // Set the fill color to light purple
  sphere(13);  // Draw a sphere for moon 7
  popMatrix();
  
  popMatrix();

  time = time + .01f;  // Increment the time variable
}
