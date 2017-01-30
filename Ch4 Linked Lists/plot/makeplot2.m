rmergeSortTime_rrf = fopen('rmergeSortTime_rrf.out', 'r');
x1 = fscanf(rmergeSortTime_rrf, '%d,%f', [2, Inf]);
rmergeSortTime = fopen('rmergeSortTime.out', 'r');
x2 = fscanf(rmergeSortTime, '%d,%f', [2, Inf]);
%x(2,:) = x(2,:) * 10e-9;
%disp(x);


fclose(rmergeSortTime_rrf);
fclose(rmergeSortTime);
plot(x1(1,:), x1(2,:), 'r.:', x2(1,:), x2(2,:), 'b.:');
xlabel('linked list size');
ylabel('msec');
legend('rmergeSortTime rrf','rmergeSortTime','Location','northwest');
