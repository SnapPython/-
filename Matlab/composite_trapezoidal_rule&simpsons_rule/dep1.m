a = 0; 
b = 1; 

n2 = 2;
n4 = 4;
n8 = 8;
n16 = 16;

result2 = compound_trapezoidal(a, b, n2);
result4 = compound_trapezoidal(a, b, n4);
result8 = compound_trapezoidal(a, b, n8);
result16 = compound_trapezoidal(a, b, n16);
fprintf('n2 %.4f\n',result2)
fprintf('n4 %.4f\n',result4)
fprintf('n8 %.4f\n',result8)
fprintf('n16 %.4f\n',result16)


