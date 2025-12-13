int dir = 1;
int v = 4;
int r = 40;
int x = r;
int a = 30;
int dira = -1;

void setup(){
  size(500,500);
  ellipseMode(RADIUS);
}

void draw(){
  background(0);
  fill(255,255,0);
  
  if(dir==1) arc(x,height/2,r,r,radians(a), radians(360-a));
  else arc(x,height/2,r,r,radians(180+a), radians(360+180-a));
  fill(0);
  ellipse(x, height/2-20,3,3);
  
  if(dist(mouseX, mouseY,x,height/2) > r){ // Blocchiamo pacman se il mouse è dentro la sua forma
    if(x>=width - r || x < r){
      dir = -dir;
    }
    x+=dir*v;
    if(a>30 || a<0) dira =- dira;
    a+=dira;
  }
  
};

/*
int x = 20;

void setup(){
  size(800,800);
}

void draw(){
  background(0);
  rect(x,height/2, 50, 50);
}

void keyPressed(){
  if(key == CODED){
    if(keyCode == LEFT) x-=5;
    else if(keyCode == RIGHT) x+=5;
  }
}
*/

/*
float [] r =  new float[5];
void setup(){
  size(500,500);
  for (int i = 0; i<r.length; i++) r[i] = i*100;
}

void draw(){
  for(int i = r.length-1; i > 0; i--){
    fill(random(0,255),random(0,255),random(0,255));
    ellipse(width/2, height/2, r[i], r[i]);
  }
}

void mousePressed(){
  noLoop();
}

void keyPressed(){
  if(key == 'a') noLoop();
}
void keyReleased(){
  loop();
}
void mouseReleased(){
  loop();
}
*/
/*
void setup(){
    size(500,500);
}

void draw(){
  if(mousePressed){
    if(mouseButton == LEFT){
      println("L");
    }
    if(mouseButton == RIGHT){
      println("R");
    }
  }
  
  if(keyPressed){
    if(key == 'a') println("Hai cliccato su a");
  }
}

void mouseReleased(){
  println("Mouse rilasciato");
}

void mouseClicked(){
  println("Mouse cliccato");
}
*/
