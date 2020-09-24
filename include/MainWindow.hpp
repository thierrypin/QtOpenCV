//
// Created by thierry on 23/09/2020.
//

#ifndef QTOPENCV_QTMAINWINDOW_HPP
#define QTOPENCV_QTMAINWINDOW_HPP

#include <memory>

#include <opencv2/opencv.hpp>

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPixmap>
#include <QTimer>
#include <QWidget>
#include <QLabel>

class MainWindow : public QMainWindow
{
public:
    MainWindow();

private:
    void draw();
    void refresh();

    /**
     * Attributes
     */
    cv::VideoCapture cap;

    // Graphic elements
    std::shared_ptr<QWidget> window;
    std::shared_ptr<QHBoxLayout> layout;

    std::shared_ptr<QLabel> lbl_dados_usuario;
    std::shared_ptr<QLabel> lbl_nome;
    std::shared_ptr<QLabel> lbl_matricula;
    std::shared_ptr<QLabel> lbl_posicionamento;

    std::shared_ptr<QLabel> nome;
    std::shared_ptr<QLabel> matricula;
    std::shared_ptr<QLabel> status_acesso;
    std::shared_ptr<QLabel> data;
    std::shared_ptr<QLabel> img;
    std::shared_ptr<QLabel> img_face;

    std::shared_ptr<QImage> frame_container;
    std::shared_ptr<QImage> face_container;

    std::shared_ptr<QPixmap> camera;
    std::shared_ptr<QPixmap> face;

    QTimer refreshTimer;
};


#endif //QTOPENCV_QTMAINWINDOW_HPP

