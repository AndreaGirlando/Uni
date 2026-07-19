clear all
close all


I=double(rgb2gray(imread('lena.jpg')));
figure, imshow(I,[]);

[m,n]=size(I);

cx=2; %fattore di scaling della x
cy=2; %fattore di scaling della y
S=[cx,0,0;0,cy,0;0,0,1]; %matrice per lo scaling

t=70;% fattore di rotazione
R=[cosd(t),sind(t),0;-sind(t),cosd(t),0;0,0,1];%matrice per la rotation

tx=100;
ty=50;
T=[1 0 0; 0 1 0; tx ty 1]; %matrice per la translation

sh=3;
sv=3;
Shv=[1 0 0; sv 1 0; 0 0 1]; % matrice per lo shear vertical
Shh=[1 sh 0; 0 1 0; 0 0 1]; % matrice per lo shear horizontal

% per combinare basta moltiplicare le matrici

C = S*T^2;

for x=1:m
    for y=1:n
        % Scorro righe e colonne della mia immagine
        M=[x,y,1]*C; % moltiplico ogni vettore (che rappresenta un pixel) con la mia matrice C 
        v=round(M(1,1));
        w=round(M(1,2));
        % fprintf('\n\nPrima: x = %d, y = %d\n', x, y);
        % fprintf('Dopo: v = %d, w = %d\n', v, w);
        % pause(0.02); 

        if v>0 & w>0
            O(v,w)=I(x,y);
        end
    end
end

figure, imshow(O,[]);