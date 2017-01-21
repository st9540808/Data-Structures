%y : time (sec)
%x : linked list size;

inputFile = fopen('output.out', 'r');
x = fscanf(inputFile, '%d,%f', [2, Inf]);
%x(2,:) = x(2,:) * 10e-9;
%disp(x);


fclose(inputFile);
plot(x(1,:),x(2,:),'r.:');
xlabel('linked list size');
ylabel('msec');
legend('insertion sort','Location','southeast');
