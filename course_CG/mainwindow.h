#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QWidget>
#include <QKeyEvent>
#include <QFileDialog>
#include <QMessageBox>

#include <memory>
#include <iostream>
#include <time.h>
#include "3d_prmitives/ball_model.h"
#include "3d_prmitives/box_model.h"

#include "scene/interface.h"
#include "commands/all.h"

#include "faq_move.h"
#include "faq_light.h"
#include "faq_hit.h"
using namespace std;

typedef QRgb** RgbMap;
#define MAX_TIME 30*60

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void keyPressEvent(QKeyEvent*);
    void mousePressEvent(QMouseEvent*);

    void on_cam_move_f_clicked();
    void on_cam_move_l_clicked();
    void on_cam_move_r_clicked();
    void on_cam_move_b_clicked();
    void on_cam_move_u_clicked();
    void on_cam_move_d_clicked();

    void on_cam_rot_u_clicked();
    void on_cam_rot_l_clicked();
    void on_cam_rot_d_clicked();
    void on_cam_rot_r_clicked();

    void on_lig_move_f_clicked();
    void on_lig_move_b_clicked();
    void on_lig_move_l_clicked();
    void on_lig_move_r_clicked();
    void on_lig_move_u_clicked();
    void on_lig_move_d_clicked();
    void on_lig_i_valueChanged(int value);

    void on_cam_info_clicked();
    void on_lig_info_clicked();

    void on_file_button_clicked();

    void on_hit_info_clicked();

private:
    Ui::MainWindow *ui;
    std::shared_ptr<QGraphicsScene> _qscene;
    SceneInterface _scene;

    QSize _scene_size;
    shared_ptr<QImage> _img;
    // QPixmap _pmap;
    void mouseMoveEvent(QMouseEvent *eventMove);
    QGraphicsPixmapItem* q_pmap;
    QColor _draw_color = Qt::black;
    RgbMap _rgb_map;
    bool _on_run = false;

    shared_ptr<FAQ_Move> _move_window;
    shared_ptr<FAQ_Light> _light_window;
    shared_ptr<FAQ_Hit> _hit_window;
    shared_ptr<QDialog> _info_window;

    vector<QColor> _color_arr = { Qt::red, Qt::green, Qt::blue, Qt::white, Qt::magenta, Qt::yellow };
    void _fill_img(QColor color);
    void _test_init();
    void _main_cycle();

    void _upd();
    void _paint();

    void _move_camera(double x, double y, double z);
    void _rotate_camera(double x, double y, double z);

    void _move_light(double x, double y, double z);
    void _change_light_i(double i);

    void _graphics_click(int x, int y);
};

#endif // MAINWINDOW_H
