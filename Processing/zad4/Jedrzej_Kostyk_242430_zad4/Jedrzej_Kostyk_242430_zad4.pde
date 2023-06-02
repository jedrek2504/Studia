float time = 0.f;
PImage background;


void setup() {
  fullScreen();                      // tryb pełnoekranowy
  background(0);                     // tło usatwione na kolor czarny
  noStroke();                        // usuwamy obwódkę wokół rysowanych figur
  background = loadImage("bg6.jpg"); // uploud tła
}


void draw() {
  background(0);                      //ustawiamy czarny kolor tła
  image(background, 0, 0);            // wyświetlamy obrazek wczytany w zmiennej background
  translate(width *.5f, height *.5f); // przesuwamy początek układu współrzędnych do środka ekranu

  //słońce
  pushMatrix();   // zapisujemy aktualny stan układu współrzędnych na stosie
  fill(#F28C38);  // ustawiamy kolor wypełnienia na pomarańczowy
  scale(70);      // skalujemy rysunek 70-krotnie
  drawCircle(50); // rysujemy koło o promieniu 50
  popMatrix();    // przywracamy zapisany stan układu współrzędnych

  //planeta 1
  pushMatrix();            // zapisujemy aktualny stan układu współrzędnych na stosie
  rotate(time*1.7f);       // obracamy rysunek o kąt zależny od zmiennej "time"
  translate(120.f, 120.f); // przesuwamy rysunek o 120 pikseli w prawo i 120 pikseli w dół
  fill(#747b81);           // ustawiamy kolor wypełnienia na szary
  scale(20);               // skalujemy rysunek 20-krotnie
  drawCircle(50);          // rysujemy koło o promieniu 50
  
  //księżyc 1
  pushMatrix();            //zapisujemy obecne ustawienie matrycy przekształceń
  rotate(time*1.f);        //obracamy figurę wokół początku układu współrzędnych
  translate(1.5f, 0);      //przesuwamy figurę o wartość x=1.5f wzdłuż osi X
  fill(#25587C);           //ustawiamy kolor wypełnienia na niebieski
  scale(0.2f);             //zmniejszamy figurę o 80% w obu kierunkach
  drawCircle(50);          //rysujemy okrąg o promieniu 50 pikseli
  popMatrix();             //przywracamy poprzednie ustawienie matrycy przekształceń
  
  //księżyc 2
  pushMatrix();
  rotate(time*3.1f);
  translate(1.5f, 1.5f);
  fill(#F4F4F4);
  scale(0.3f);
  drawCircle(50);
  popMatrix();
  
  popMatrix();

  //planeta 2
  pushMatrix();
  rotate(time*0.7f);
  translate(200.f, 200.f);
  fill(#968396);
  scale(35);
  drawCircle(50);
  
  //księżyc 3
  pushMatrix();
  rotate(time*7.f);
  translate(1.5f, 0);
  fill(#CACACA);
  scale(0.26f);
  drawCircle(50);
  popMatrix();
  
  popMatrix(); 

  //planeta 3
  pushMatrix();  
  rotate(time*2.1f);
  translate(270.f, 270.f);
  fill(#8CB1DE);
  scale(40);
  drawCircle(50);
  
  //księżyc 4
  pushMatrix();
  rotate(time*3.f);
  translate(1.5f, 0);
  fill(#FEFCD7);
  scale(0.15f);
  drawCircle(50);
  popMatrix();
  
  popMatrix();

  //planeta 4
  pushMatrix();
  rotate(time*1.2f);
  translate(450, 450);
  fill(#9C2E35);
  scale(30);
  drawCircle(50);
  
  //księżyc 5
  pushMatrix();
  rotate(time*3.9f);
  translate(0.7f, 1.2f);
  fill(#122F50);
  scale(0.2f);
  drawCircle(50);
  popMatrix();
  
  //księżyc 6
  pushMatrix();
  rotate(time*2.2f);
  translate(1.7f, 0f);
  fill(#3AA8C2);
  scale(0.36f);
  drawCircle(3);
  popMatrix();
  
  //księżyc 7
  pushMatrix();
  rotate(time*1.6f);
  translate(-3.f, 0f);
  fill(#CED0F5);
  scale(0.5f);
  drawCircle(50);
  popMatrix();
  
  popMatrix();

  //czas
  time = time + .01f;
}


void drawCircle(int steps)
{
  beginShape();
  for (int i = 0; i < steps; ++i)
    vertex(cos(TWO_PI * (float)i / float(steps)), sin(TWO_PI * (float)i / float(steps)));
  endShape();
}
