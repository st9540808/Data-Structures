%y : time (sec)
%x : linked list size;

insertionSortTime = fopen('insertionSortTime.out', 'r');
x1 = fscanf(insertionSortTime, '%d,%f', [2, Inf]);
rmergeSortTime = fopen('rmergeSortTime.out', 'r');
x2 = fscanf(rmergeSortTime, '%d,%f', [2, Inf]);
%x(2,:) = x(2,:) * 10e-9;
%disp(x);


fclose(insertionSortTime);
fclose(rmergeSortTime);
plot(x1(1,:), x1(2,:), 'r.:', x2(1,:), x2(2,:), 'b.:');
xlabel('linked list size');
ylabel('msec');
legend('insertion sort','recursive merge sort','Location','northwest');
