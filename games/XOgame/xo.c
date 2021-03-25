#include <stdio.h>

int xogame(char **bf, const int field_size, const char symb)
{
    int kx, ko, k, jk, ik, max_ik, max_jk, max;
    char antisymb;
    
    ik = 0;
    jk = 0;
    k = 0;
    kx = 0;
    ko = 0;
    
    if (symb == 'X')
        antisymb = 'O';
    else
        antisymb = 'X';
   
// Проверка на возможную победу
        
    for (int i=0; i<field_size; i++)
    {
        for (int j=0; j<field_size; j++)
        {
            if (bf[i][j] == symb)
                kx++;
            if (bf[i][j] == ' ')
            {
                k++;
                jk = j;
            }
        }
        
        if ((kx == field_size - 1) && (k == 1))
            return i * field_size + jk;

        k = 0;
        kx = 0;
    }
        
        
    for (int j=0; j<field_size; j++)
    {
        for (int i=0; i<field_size; i++)
        {
            if (bf[i][j] == symb)
                kx++;
            if (bf[i][j] == ' ')
            {
                k++;
                ik = i;
            }
        }

        if ((kx == field_size - 1) && (k == 1))
            return ik * field_size + j;

        k = 0;
        kx = 0;
    }
        
        
    for (int i=0; i<field_size; i++)
    {
        if (bf[i][i] == symb)
            kx++;
        if (bf[i][i] == ' ')
        {
            k++;
            ik = i;
        }
    }

    if ((kx == field_size - 1) && (k == 1))
        return ik * field_size + ik;

    k = 0;
    kx = 0;
        
    for (int i=0; i<field_size; i++)
    {
        if (bf[i][field_size - 1 - i] == symb)
            kx++;
        if (bf[i][field_size - 1 - i] == ' ')
        {
            k++;
            ik = i;
        }
    }

    if ((kx == field_size - 1) && (k == 1))
        return ik * field_size + field_size - 1 - ik;

    k = 0;
    kx = 0;
        
// Проверка на возможный проигрыш
        
    for (int i=0; i<field_size; i++)
    {
        for (int j=0; j<field_size; j++)
        {
            if (bf[i][j] == antisymb)
                kx++;
            if (bf[i][j] == ' ')
            {
                k++;
                jk = j;
            }
        }

        if ((kx == field_size - 1) && (k == 1))
            return i * field_size + jk;

        k = 0;
        kx = 0;
    }
        
        
    for (int j=0; j<field_size; j++)
    {
        for (int i=0; i<field_size; i++)
        {
            if (bf[i][j] == antisymb)
                kx++;
            if (bf[i][j] == ' ')
            {
                k++;
                ik = i;
            }
        }

        if ((kx == field_size - 1) && (k == 1))
            return ik * field_size + j;

        k = 0;
        kx = 0;
    }
        
    for (int i=0; i<field_size; i++)
    {
        if (bf[i][i] == antisymb)
            kx++;
        if (bf[i][i] == ' ')
        {
            k++;
            ik = i;
        }
    }

    if ((kx == field_size - 1) && (k == 1))
        return ik * field_size + ik;

    k = 0;
    kx = 0;
        
    for (int i=0; i<field_size; i++)
    {
        if (bf[i][field_size - 1 - i] == antisymb)
            kx++;
        if (bf[i][field_size - 1 - i] == ' ')
        {
            k++;
            ik = i;
        }
    }

    if ((kx == field_size - 1) && (k == 1))
        return ik * field_size + field_size - 1 - ik;

    k = 0;
    kx = 0;
        
//Конец проверки
    
    if (bf[field_size / 2][field_size / 2] == ' ')
    return (field_size / 2) * field_size + field_size / 2;
    
    if (bf[0][0] == ' ')
        return 0;
    else if (bf[0][field_size-1] == ' ')
        return field_size - 1;
    else if (bf[field_size-1][0] == ' ')
        return (field_size - 1) * field_size;
    else if (bf[field_size-1][field_size-1] == ' ')
        return (field_size - 1) * field_size + field_size - 1;
    
//Нахождение оптимального хода
    
    max_ik = -1;
    max_jk = -1;
    max = -1;
    
    for (int i=0; i<field_size; i++)
    {
        if (bf[i][i] == symb)
            kx++;
        else if (bf[i][i] == antisymb)
            ko++;
        else
        {
            k++;
            ik = i;
        }
    }

    if ((ko == 0) && (k > 0) && (kx > max))
    {
        max_ik = ik;
        max_jk = ik;
        max = kx;
    }

    k = 0;
    kx = 0;
    ko = 0;
        
    for (int i=0; i<field_size; i++)
    {
        if (bf[i][field_size - 1 - i] == symb)
            kx++;
        else if (bf[i][field_size - 1 - i] == antisymb)
            ko++;
        else
        {
            k++;
            ik = i;
        }
    }

    if ((ko == 0) && (k > 0) && (kx > max))
    {
        max_ik = ik;
        max_jk = field_size - 1 - ik;
        max = kx;
    }
    k = 0;
    kx = 0;
    ko = 0;
    
    for (int i=0; i<field_size; i++)
    {
        for (int j=0; j<field_size; j++)
        {
            if (bf[i][j] == symb)
                kx++;
            else if (bf[i][j] == antisymb)
                ko++;
            else
            {
                k++;
                jk = j;
            }
        }

        if ((ko == 0) && (k > 0) && (kx > max))
        {
            max_ik = i;
            max_jk = jk;
            max = kx;
        }

        k = 0;
        kx = 0;
        ko = 0;
    }
        
        
    for (int j=0; j<field_size; j++)
    {
        for (int i=0; i<field_size; i++)
        {
            if (bf[i][j] == symb)
                kx++;
            else if (bf[i][j] == antisymb)
                ko++;
            else
            {
                k++;
                ik = i;
            }
        }
        if ((ko == 0) && (k > 0) && (kx > max))
        {
            max_ik = ik;
            max_jk = j;
            max = kx;
        }
        k = 0;
        kx = 0;
        ko = 0;
    }
    
    if (max > -1)
        return max_ik * field_size + max_jk;
    
// Заполнение оставшихся клеток
    
    for (int i=0; i<field_size; i++)
    {
        for (int j=0; j<field_size; j++)
        {
            if (bf[i][j] == ' ')
                return i * field_size + j;
        }
    }
    return -1;
}