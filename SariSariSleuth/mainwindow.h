#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stockmodel.h"
#include "transactionmodel.h"
#include "confirmedtransactionmodel.h"
#include "analyticsmodel.h"
#include "howmuchmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();

    private slots:
        void onAddButtonClicked();
        void onEditButtonClicked();
        void onDeleteButtonClicked();
        void onFilterTextChanged(const QString &text);
        void onManualAddClicked();
        void onConfirmTransactionClicked();
        void onDeleteTransactionClicked();
        void onTimePeriodChanged(int index);
        void onDaysToStockChanged(int days);
        void onBackupButtonClicked();
        void onRestoreButtonClicked();

    protected:
        void keyPressEvent(QKeyEvent *event) override;

    private:
        Ui::MainWindow *ui;
        StockModel *stockModel;
        TransactionModel *transactionModel;
        ConfirmedTransactionModel *confirmedTransactionModel;
        AnalyticsModel *analyticsModel;
        HowMuchModel *howMuchModel;
};

#endif
