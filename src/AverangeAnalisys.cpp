#include "AverangeAnalisys.h"

AverangeAnalisys::AverangeAnalisys()
{
}

double AverangeAnalisys::analyze(const QList<double> &values) const
{
    if(values.isEmpty())
    {
        return 0;
    }

    const double sum = AbstractAnalysis::listSum(values);
    const double result = sum / static_cast<double>(values.length());

    return result;
}
