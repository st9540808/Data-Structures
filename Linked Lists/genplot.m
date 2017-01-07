%y = [1:500];
%x = [1:500];

inputFile = fopen('output.out', 'r');
x = fscanf(inputFile, '%d,%f', [2, Inf]);
x(2,:) = x(2,:)/10e9;
%disp(x);


fclose(inputFile);
plot(x(1,:),x(2,:),'r.');
xlabel('linked list size');
ylabel('sec');
legend('insertion sort','Location','southeast');
