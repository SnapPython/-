function x = gauss_elimination_with_pivoting(A, b)
% 获取矩阵A的行数
n = size(A, 1);

% 增广矩阵
augmented_matrix = [A, b];

% 消元
for k = 1 : n - 1
    % 列主元选取
    [~, pivot_row] = max(abs(augmented_matrix(k : n, k)));
    pivot_row = pivot_row + k - 1;

    % 如果主元为0，无法求解
    if augmented_matrix(pivot_row, k) == 0
        error('主元为0，无法求解');
    end

    % 交换当前行和主元所在行
    augmented_matrix([k, pivot_row], :) = augmented_matrix([pivot_row, k], :);

    % 消元
    for i = k + 1 : n
        factor = augmented_matrix(i, k) / augmented_matrix(k, k);
        augmented_matrix(i, k : n + 1) = augmented_matrix(i, k : n + 1) - factor * augmented_matrix(k, k : n + 1);
    end
end

% 回代求解
x = zeros(n, 1);
x(n) = augmented_matrix(n, n + 1) / augmented_matrix(n, n);
for i = n - 1 : -1 : 1
    x(i) = (augmented_matrix(i, n + 1) - augmented_matrix(i, i + 1 : n) * x(i + 1 : n)) / augmented_matrix(i, i);
end
end