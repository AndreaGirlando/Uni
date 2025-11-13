//oltre alla variabile mousePressed, esiste anche la funzione mousePressed (quindi si scrive void mousePressed), stessa cosa per releasedMouse
float [] r=new float[5];

void setup(){
  size(800,800);
  for (int i=0; i<r.length;i++){
    r[i]=i*100;
  }
}

void draw(){
  for (int i=r.length-1;i>=0;i--){
    fill(random(0,255),random(0,255),random(0,255));
    ellipse(width/2,height/2, r[i],r[i]);
            
  }
}

void mousePressed(){
  noLoop();
 }
 
void mouseReleased(){
  loop();
}