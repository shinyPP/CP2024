%% readin
data2 = table2array(readtable("data_2.txt"));
data3 = table2array(readtable("data_3.txt"));
data4 = table2array(readtable("data_4.txt"));
data5 = table2array(readtable("data_5.txt"));

%% energy per spin
plot(data2(:,1),data2(:,2)/4)
hold on
plot(data3(:,1),data3(:,2)/9)
hold on
plot(data4(:,1),data4(:,2)/16)
hold on
plot(data5(:,1),data5(:,2)/25)
hold off
xlabel('T/IJI')
ylabel('H/J')
title('energy per spin in square lattice')
%% specific heat per spin
plot(data2(:,1),data2(:,3)/4)
hold on
plot(data3(:,1),data3(:,3)/9)
hold on
plot(data4(:,1),data4(:,3)/16)
hold on
plot(data5(:,1),data5(:,3)/25)
hold off
xlabel('T/IJI')
ylabel('C')
title('specific heat per spin in square lattice')
%% <M^2>/N^2
plot(data2(:,1),data2(:,4)/16)
hold on
plot(data3(:,1),data3(:,4)/81)
hold on
plot(data4(:,1),data4(:,4)/256)
hold on
plot(data5(:,1),data5(:,4)/625)
hold off
xlabel('T/IJI')
ylabel('M^2')
title('M^2 per spin in square lattice')
%% comparison of 2 by 2 square in energy
x=0.01:0.01:4;
y = -8*(1-exp(-16./x))./(1+6*exp(-8./x)+exp(-16./x));
scatter(data2(:,1),data2(:,2)/4)
hold on
plot(x,(8+y)/4)
hold off
xlabel('T/IJI')
ylabel('H/J')
title('energy per spin in square lattice')
%% comparison of 2 by 2 square inmagnetization
x=0.01:0.01:4;
y = (1+exp(-8./x))./(1+6*exp(-8./x)+exp(-16./x));
scatter(data2(:,1),data2(:,4)/16)
hold on
plot(x,y)
hold off
xlabel('T/IJI')
ylabel('M^2')
title('M^2 per spin in square lattice')