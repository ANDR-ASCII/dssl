#pragma once

namespace DSSL
{

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

private:
    QGraphicsScene* m_scene;
};

}