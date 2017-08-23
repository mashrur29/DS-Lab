#include<stdio.h>

int mat_mul__(int i, int j, int k, int mat1[100][100], int mat2[100][100], int res[100][100], int r1, int r2, int r3, int c1, int c2, int c3)
{
    if(k>r2) return 0;
    return mat1[i][k]*mat2[k][j]+mat_mul__(i, j, k+1, mat1, mat2, res, r1, r2, r3, c1, c2, c3);
}

void mat_mul_(int i, int j, int k, int mat1[100][100], int mat2[100][100], int res[100][100], int r1, int r2, int r3, int c1, int c2, int c3)
{
    if(j>c3) return;
    res[i][j] = mat_mul__(i, j, 1, mat1, mat2, res, r1, r2, r3, c1, c2, c3);
    mat_mul_(i, j+1, k, mat1, mat2, res, r1, r2, r3, c1, c2, c3);
}

void mat_mul(int i, int j, int k, int mat1[100][100], int mat2[100][100], int res[100][100], int r1, int r2, int r3, int c1, int c2, int c3)
{
    if(i>r3) return;
    mat_mul_(i, 1, k, mat1, mat2, res, r1, r2, r3, c1, c2, c3);
    mat_mul_(i, j, 1, mat1, mat2, res, r1, r2, r3, c1, c2, c3);
    mat_mul(i+1, j, k, mat1, mat2, res, r1, r2, r3, c1, c2, c3);
}

int main()
{
    int r3, c3, r1, r2, c1, c2, mat1[100][100], mat2[100][100], res[100][100];

    scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
    r3 = r1;
    c3 = c2;

    for(int i=1; i<100; i++) res[i][i] = 1;

    for(int i=1; i<=r1; i++)
    {
        for(int j=1; j<=c1; j++)
            scanf("%d", &mat1[i][j]);
    }

    for(int i=1; i<=r2; i++)
    {
        for(int j=1; j<=c2; j++)
            scanf("%d", &mat2[i][j]);
    }

    mat_mul(1, 1, 1, mat1, mat2, res, r1, r2, r3, c1, c2, c3);

    for(int i=1; i<=r3; i++)
    {
        for(int j=1; j<=c3; j++) printf("%d ", res[i][j]);
        puts("");
    }

    return 0;
}
