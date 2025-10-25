clear all
close all


I=double(rgb2gray(imread('lena.jpg')));
figure, imshow(I,[]);

[m,n]=size(I);


cx=2;
cy=2;
S=[cx,0,0;0,cy,0;0,0,1];

t=70;%espresso in gradi
R=[cosd(t),sind(t),0;-sind(t),cosd(t),0;0,0,1];

tx=100;
ty=50;
T=[1 0 0; 0 1 0; tx ty 1];

sh=3;
sv=3;
Shv=[1 0 0; sv 1 0; 0 0 1];
Shh=[1 sh 0; 0 1 0; 0 0 1]

%per combinare basta moltiplicare le matrici

%C=T*S*R;
%C=R*S*T;

C=S;


for x=1:m
    for y=1:n
        %        [v,w,1]=[x,y,1]*S; %questo è quello che vorremmo fare
        M=[x,y,1]*C;
        v=round(M(1,1));
        w=round(M(1,2));
        if v>0 & w>0
            O(v,w)=I(x,y);
        end
    end
end

figure, imshow(O,[]);