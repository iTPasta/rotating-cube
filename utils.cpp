

double min(double f1, double f2)
{
    return f1 < f2 ? f1 : f2;
}

double max(double f1, double f2)
{
    return (f1 < f2) ? f2 : f1;
}

double max(double f1, double f2, double f3)
{
    return max(f1, max(f2, f3));
}

double distance(double f1, double f2)
{
    double d = f2 - f1;
    return d >= 0 ? d : -d;
}