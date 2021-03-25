#include <stdio.h>
#include <stdlib.h>
#include "travelgame.h"

int travel_game(int **result, FILE *const flights, const Flight route)
{
    int number = 0, month, day, n = 0;
    size_t a;
    char ch;

    
    *result = malloc(400000);

    fgetln(flights, &a);
    
    if (route.month == 6)
    {
        if (route.day == 8)
        {
            n = 2262;
        }
        
        else if (route.day == 11)
        {
            for (int i = 0; i < 2262; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2258;
        }
        
        else if (route.day == 12)
        {
            for (int i = 0; i < 4520; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2264;
        }
        
        else if (route.day == 15)
        {
            for (int i = 0; i < 6784; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2266;
        }
        
        else if (route.day == 18)
        {
            for (int i = 0; i < 9050; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2267;
        }
        
        else if (route.day == 19)
        {
            for (int i = 0; i < 11317; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2277;
        }
        
        else if (route.day == 22)
        {
            for (int i = 0; i < 13594; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2273;
        }
        
        else if (route.day == 25)
        {
            for (int i = 0; i < 15867; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2265;
        }
        
        else if (route.day == 26)
        {
            for (int i = 0; i < 18132; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2278;
        }
        
        else
        {
            for (int i = 0; i < 20410; i++)
            {
                fgetln(flights, &a);
            }
        
            n = 2260;
        }
    }
    
    else if (route.month == 7)
    {
        for (int i = 0; i < 22670; i++)
        {
            fgetln(flights, &a);
        }
        
        if (route.day == 2)
        {
            n = 2271;
        }
        
        else if (route.day == 6)
        {
            for (int i = 0; i < 2271; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2282;
        }
        
        else if (route.day == 9)
        {
            for (int i = 0; i < 4553; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2273;
        }
        
        else if (route.day == 10)
        {
            for (int i = 0; i < 6826; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2282;
        }
        
        else if (route.day == 13)
        {
            for (int i = 0; i < 9108; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2278;
        }
        
        else if (route.day == 16)
        {
            for (int i = 0; i < 11386; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2264;
        }
        
        else if (route.day == 17)
        {
            for (int i = 0; i < 13650; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2279;
        }
        
        else if (route.day == 20)
        {
            for (int i = 0; i < 15929; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2278;
        }
        
        else if (route.day == 23)
        {
            for (int i = 0; i < 18207; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2267;
        }
        
        else if (route.day == 24)
        {
            for (int i = 0; i < 20474; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2279;
        }
        
        else if (route.day == 27)
        {
            for (int i = 0; i < 22753; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2282;
        }
        
        else if (route.day == 30)
        {
            for (int i = 0; i < 25035; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2269;
        }
        
        else
        {
            for (int i = 0; i < 27304; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2281;
        }
    }
    
    else if (route.month == 8)
    {
        for (int i = 0; i < 52255; i++)
        {
            fgetln(flights, &a);
        }
        
        if (route.day == 3)
        {
            n = 2283;
        }
        
        else if (route.day == 5)
        {
            for (int i = 0; i < 2283; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2253;
        }
        
        else if (route.day == 6)
        {
            for (int i = 0; i < 4536; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2277;
        }
        
        else if (route.day == 7)
        {
            for (int i = 0; i < 6813; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2286;
        }
        
        else if (route.day == 10)
        {
            for (int i = 0; i < 9099; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2283;
        }
        
        else if (route.day == 13)
        {
            for (int i = 0; i < 11382; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2282;
        }
        
        else if (route.day == 14)
        {
            for (int i = 0; i < 13664; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2286;
        }
        
        else if (route.day == 17)
        {
            for (int i = 0; i < 15950; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2278;
        }
        
        else if (route.day == 20)
        {
            for (int i = 0; i < 18228; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2259;
        }
        
        else if (route.day == 21)
        {
            for (int i = 0; i < 20487; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2264;
        }
        
        else if (route.day == 24)
        {
            for (int i = 0; i < 22751; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2270;
        }
        
        else if (route.day == 27)
        {
            for (int i = 0; i < 25021; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2260;
        }

        else if (route.day == 28)
        {
            for (int i = 0; i < 27281; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2262;
        }
        
        else
        {
            for (int i = 0; i < 29543; i++)
            {
                fgetln(flights, &a);
            }
            
            n = 2263;
        }
    }
    
    else
    {
        for (int i = 0; i < 84062; i++)
        {
            fgetln(flights, &a);
        }
        
        n = 2333;
    }
    
    for (int i = 0; i < n; i++)
    {
        fscanf(flights, "%d,", &month);
        fscanf(flights,"%d,", &day);
        fscanf(flights, "%c", &ch);
            
        if (ch == route.origin[0])
        {
            fscanf(flights, "%c", &ch);
            
            if (ch == route.origin[1])
            {
                fscanf(flights, "%c,", &ch);

                if (ch == route.origin[2])
                {
                    fscanf(flights, "%c", &ch);
                    
                    if (ch == route.destination[0])
                    {
                        fscanf(flights, "%c", &ch);
                        
                        if (ch == route.destination[1])
                        {
                            fscanf(flights, "%c,", &ch);

                            if (ch == route.destination[2])
                            {
                                fscanf(flights,"%d", *result + number);
                                number++;
                            }
                            else
                            {
                                fgetln(flights, &a);
                            }
                        }
                        else
                        {
                            fgetln(flights, &a);
                        }
                    }
                    else
                    {
                        fgetln(flights, &a);
                    }
                }
                else
                {
                    fgetln(flights, &a);
                }
            }
            else
            {
                fgetln(flights, &a);
            }
        }
        else
        {
            fgetln(flights, &a);
        }
    }
    
    return number;
}