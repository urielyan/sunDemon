#include "includes.h"
#include "DataBase.h"

#include "ComputeKBValue.h"
#include "ui_ComputeKBValue.h"



#include <QSqlTableModel>
#include <QDebug>
#include <QMessageBox>

ComputeKBValue::ComputeKBValue(QWidget *parent) :
    Widget(parent),
    ui(new Ui::ComputeKBValue)
{
    ui->setupUi(this);
}

ComputeKBValue::~ComputeKBValue()
{
    delete ui;
}

bool ComputeKBValue::init()
{
    DataBaseManager *db = MAIN_WINDOW->db();
    QSqlTableModel *calibrateModel = db->model("calibrateData");
    QSqlTableModel *percentageModel = db->model("calibratePercentage");

    int calibrateRowCount = calibrateModel->rowCount();
    if (calibrateRowCount < 3 )
    {
        QMessageBox::warning(this, tr("标定错误"), tr("标定样品数据太少"));
        return false;
    }
    QMap<int, double> validPercentages;
    for (int i = 0; i < calibrateRowCount; ++i)
    {
        QModelIndex idx = percentageModel->index(i, 1);
        bool ok = false;
        double data = percentageModel->data(idx).toDouble(&ok);
        if(ok == true && data > 0.0)
        {
            validPercentages.insert(i, data);
        }
    }
    if (validPercentages.count() < 3 )
    {
        QMessageBox::warning(this, tr("标定错误"), tr("输入硫数据太少"));
        return false;
    }
    return true;
}

void ComputeKBValue::on_computeKBValue_clicked()
{
    DataBaseManager *db = MAIN_WINDOW->db();
    QSqlTableModel *calibrateModel = db->model("calibrateData");
    QSqlTableModel *percentageModel = db->model("calibratePercentage");

    int calibrateRowCount = calibrateModel->rowCount();

    QMap<int, double> validPercentages;
    int validPercentageCount = 0;
    for (int i = 0; i < calibrateRowCount; ++i)
    {
        QModelIndex idx = percentageModel->index(i, 1);
        bool ok = false;
        double data = percentageModel->data(idx).toDouble(&ok);
        if(ok == true && data > 0.0)
        {
            validPercentages.insert(i, data);
        }
    }
    validPercentageCount = validPercentages.count();

    QMap <int, double> referenceProportionTested;
    foreach (int row, validPercentages.keys()) {
        QModelIndex referenceIDX = calibrateModel->index(row, 0);
        QModelIndex testedIDX = calibrateModel->index(row, 1);

        double reference = calibrateModel->data(referenceIDX).toDouble();
        double tested = calibrateModel->data(testedIDX).toDouble();
        double proportion = reference / tested;
        referenceProportionTested.insert(row, proportion);
    }

    double RPTSum = 0;  //参考样/待测样的和
    double inputSSum = 0;   // 输入硫的和
    double RPTMultiplyInputSSum = 0;
    double RPTPow2Sum = 0;
    double RPTSumAverage = 0; //参考样/待测样的和的平均值
    double inputSSumAverage = 0; //输入硫的和的平均值

    //(参考样 减去 (参考样/待测样的和的平均值)) 乘以
    //(标定样 减去 (输入硫的和的平均值))
    double RPTOffsetMultiInputSOffset = 0;

    //(参考样 减去 (参考样/待测样的和的平均值)) 的平方
    double RPTOffsetPow2 = 0;

    //(标定样 减去 (输入硫的和的平均值)) 的平方
    double inputSOffsetPow2 = 0;

    foreach (int i, referenceProportionTested.keys()) {
        RPTSum += referenceProportionTested.value(i);
        inputSSum += validPercentages.value(i);
        RPTMultiplyInputSSum += referenceProportionTested.value(i)
                * validPercentages.value(i);
        RPTPow2Sum += pow(referenceProportionTested.value(i), 2);
    }
    RPTSumAverage = RPTSum / validPercentageCount;
    inputSSumAverage = inputSSum / validPercentageCount;

    foreach (int i, referenceProportionTested.keys()) {
        double subRPT = referenceProportionTested.value(i) - RPTSumAverage;
        double subInputS = validPercentages.value(i) - inputSSumAverage;
        RPTOffsetMultiInputSOffset = subRPT * subInputS;
        RPTOffsetPow2 = pow(subRPT, 2);
        inputSOffsetPow2 = pow(subInputS, 2);
    }

    double sameDenominator = validPercentageCount * RPTPow2Sum
            - pow(RPTSum, 2);
    double k = (RPTMultiplyInputSSum * validPercentageCount -
            RPTSum * inputSSum ) / sameDenominator ;
    double b = (inputSSum * RPTPow2Sum - RPTSum * RPTMultiplyInputSSum)
            / sameDenominator;
    double r = RPTOffsetMultiInputSOffset /
            pow(RPTOffsetPow2 * inputSOffsetPow2, 0.5);

    QString str = QString("k = %1, b = %2, r = %3")
            .arg(k, 4, 'f', 4, '0')
            .arg(b, 4, 'f', 4, '0')
            .arg(r, 4, 'f', 4, '0');

}
