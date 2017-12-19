#pragma once

namespace DSSL
{

class GraphicsScene;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private slots:
    void onClickStartButton();
    void onClickStopButton();
    void onClickEnableDisableShowingDetailedInfo();

private:
    GraphicsScene* m_scene;
};

}