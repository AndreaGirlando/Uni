clear all
close all

I=imread('lena.jpg');
figure,imshow(I);

figure,imshow(I(:,:,1)),title('rosso');
figure,imshow(I(:,:,2)),title('verde');
figure,imshow(I(:,:,3)),title('blu');

figure,mesh(I(:,:,1));
figure,surf(I(:,:,1));
return

figure,mesh(I(:,:,2));
figure,mesh(I(:,:,3));