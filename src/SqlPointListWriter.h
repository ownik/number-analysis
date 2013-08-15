#ifndef SQLPOINTLISTWRITER_H

#define SQLPOINTLISTWRITER_H

#include "SqlPointListInterface.h"
#include "AbstractAnalysis.h"

class SqlPointListWriter : public SqlPointListInterface
{
public:
    SqlPointListWriter(const QString &dataBaseName, const QString& tableName);

    void write(const ID &item, const PointList &points);

    bool prepareQueries();

private:
    QSqlQuery writePointsByID_;
};

#endif // SQLPOINTLISTWRITER_H
