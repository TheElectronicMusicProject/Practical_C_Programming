#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

static int32_t
float_to_fixed (float number, int32_t scaling)
{
    int32_t out_num = round(number * (float) scaling);

    return (out_num);
}

static int32_t
fixed_mul (int32_t num1, int32_t num2, int32_t scaling)
{
    int32_t out_num = ((int64_t) num1 * (int64_t) num2) / scaling;

    return (out_num);
}

static int32_t
fixed_div (int32_t num1, int32_t num2, int32_t scaling)
{
    int32_t out_num = ((int64_t) num1 * scaling) / num2;

    return (out_num);
}

static float
fixed_to_float (int32_t number, int32_t scaling)
{
    float out_num = (((float) number) / (float) scaling);

    return (out_num);
}


int
main (int argc, char ** argv)
{
    /**
     * Fattore di scaling = 2^16 = 65536.
     */
    const int32_t   scaling_factor = (1 << 16);
    float           in_number1 = -2.03;
    float           in_number2 = 12e-3;
    float           in_result = 0.0;

    int32_t num1 = float_to_fixed(in_number1, scaling_factor);
    int32_t num2 = float_to_fixed(in_number2, scaling_factor);
    int32_t result = 0;

    result = num1 + num2;
    in_result = fixed_to_float(result, scaling_factor);
    printf("%f + %f = %f\n", in_number1, in_number2, in_result);

    result = num1 - num2;
    in_result = fixed_to_float(result, scaling_factor);
    printf("%f - %f = %f\n", in_number1, in_number2, in_result);

    result = fixed_mul(num1, num2, scaling_factor);
    in_result = fixed_to_float(result, scaling_factor);
    printf("%f * %f = %f\n", in_number1, in_number2, in_result);

    result = fixed_div(num1, num2, scaling_factor);
    in_result = fixed_to_float(result, scaling_factor);
    printf("%f / %f = %f\n", in_number1, in_number2, in_result);

    return (0);
}