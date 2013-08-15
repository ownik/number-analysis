#ifndef SQLPOINTLISTINTERFACE_H

#define SQLPOINTLISTINTERFACE_H

#include <QSqlQuery>
#include <QSqlError>
#include <QStringList>
#include <QDebug>

typedef QString ColumnsName;

class SqlPointListInterface
{
    friend class AnalysisWindow;
    friend class BSqlPointListInterface;
    friend class BSqlPointListReadWrite;

public:
    SqlPointListInterface(const QString &dataBaseName, const QString &tableName);

    virtual ~SqlPointListInterface();

    QString dataBaseName() const;
    QSqlDatabase dataBase() const;
    QString tableName() const;

    virtual bool prepareQueries() = 0;
    bool isOpen() const;


    static const ColumnsName& columnID();
    static const ColumnsName& columnNUM();
    static const ColumnsName& columnVALUE();


protected:
    bool open();
    bool execQuery(QSqlQuery &query, const QString& queryStr);
    bool createTable(QSqlQuery &query);
    static void removeConnection();

private:
    QSqlDatabase dataBase_;
    const QString dataBaseName_;

    const QString tableName_;

    static const QString connectionName_;

    static const ColumnsName columnID_;
    static const ColumnsName columnNUM_;
    static const ColumnsName columnVALUE_;

    bool open_;


};

#endif // SQLPOINTLISTINTERFACE_H
