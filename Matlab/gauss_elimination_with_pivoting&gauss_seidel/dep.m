% 系数矩阵A
A = [10, -2, -1;
    -2, 10, -1;
     -1, -2, 5];
% 常数项向量b
b = [3; 15; 10];

% 调用函数求解
solution1 = gauss_elimination_with_pivoting(A, b);
solution2 = gauss_seidel(A,b,1000,0.0001);
disp(solution1);

disp(solution2);