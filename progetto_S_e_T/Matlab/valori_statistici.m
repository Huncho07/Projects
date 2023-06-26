close all;
clc;

num_rilevazioni = 10000;

media_valori = mean(rilevazione);
dev_standard = std(rilevazione);
inc_tipo_A = dev_standard/(sqrt(num_rilevazioni));

figure;
title("Istogramma valori");
hold on;
xlabel("Valori assunti");
ylabel("Frequenza valori");
istogramma = histogram(rilevazione);
