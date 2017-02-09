imergeSortTime = fopen('imergeSortTime.out', 'r');
x1 = fscanf(imergeSortTime, '%d,%f', [2, Inf]);
rmergeSortTime = fopen('rmergeSortTime.out', 'r');
x2 = fscanf(rmergeSortTime, '%d,%f', [2, Inf]);
naturalmergeSortTime = fopen('naturalmergeSortTime.out', 'r');
x3 = fscanf(naturalmergeSortTime, '%d,%f', [2, Inf]);
timSortTime = fopen('timSortTime.out', 'r');
x4 = fscanf(timSortTime, '%d,%f', [2, Inf]);

%x(2,:) = x(2,:) * 10e-9;
%disp(x);

fclose(imergeSortTime);
fclose(rmergeSortTime);
fclose(naturalmergeSortTime);
fclose(timSortTime);

plot(x1(1,:), x1(2,:), 'r.-');
hold on
plot(x2(1,:), x2(2,:), 'bs-');
plot(x3(1,:), x3(2,:), 'k.-');
plot(x4(1,:), x4(2,:), 'm.-');
xlabel('linked list size');
ylabel('msec');
legend('imergeSortTime','rmergeSortTime','naturalmergeSortTime','timSortTime','Location','northwest');
