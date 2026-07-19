size(480,120);
strokeWeight(12);

rect(60, 25, 70, 70); //stroke di default

strokeJoin(ROUND);
rect(160, 25, 70, 70); //stroke arrotondato

strokeJoin(BEVEL);
rect(260, 25, 70, 70); //stroke "tagliato" alla punta

strokeJoin(MITER);
rect(360, 25, 70, 70); //ritorno allo stroke di default