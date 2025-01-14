#-------------------------------------------------
#
# Project created by QtCreator 2020-07-09T17:16:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = course_CG
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    3d_prmitives/point.cpp \
    3d_prmitives/vector.cpp \
    3d_prmitives/polygon.cpp \
    errors/base_error.cpp \
    3d_prmitives/model.cpp \
    3d_prmitives/ball_model.cpp \
    3d_prmitives/box_model.cpp \
    errors/objects.cpp \
    errors/primitives.cpp \
    objects/scene_object.cpp \
    objects/simple_object.cpp \
    objects/leg.cpp \
    objects/camera.cpp \
    objects/light_source.cpp \
    objects/visitors/object_visitor.cpp \
    errors/visual.cpp \
    visual/drawer.cpp \
    visual/visualizer.cpp \
    errors/managers.cpp \
    managers/base_manager.cpp \
    scene/scene.cpp \
    commands/base_command.cpp \
    commands/draw_cmd.cpp \
    commands/init_draw_cmd.cpp \
    managers/draw_mng.cpp \
    managers/init_draw_mng.cpp \
    objects/visitors/draw_visitor.cpp \
    visual/projected_model.cpp \
    transform/trans_action.cpp \
    managers/trasform_mng.cpp \
    commands/transform_cmd.cpp \
    objects/cue_ball.cpp \
    objects/plate.cpp \
    3d_prmitives/skirting.cpp \
    objects/rails.cpp \
    3d_prmitives/mplate.cpp \
    objects/composite_object.cpp \
    objects/table.cpp \
    updater/rail_contour.cpp \
    updater/updater.cpp \
    managers/update_mng.cpp \
    objects/visitors/update_visitor.cpp \
    commands/update_cmd.cpp \
    managers/build_mng.cpp \
    errors/builder_errors.cpp \
    commands/builder_cmd.cpp \
    faq_move.cpp \
    faq_light.cpp \
    faq_hit.cpp

HEADERS += \
        mainwindow.h \
    3d_prmitives/model.h \
    3d_prmitives/point.h \
    3d_prmitives/vector.h \
    3d_prmitives/polygon.h \
    errors/base_error.h \
    3d_prmitives/vertex.h \
    3d_prmitives/ball_model.h \
    3d_prmitives/box_model.h \
    scene/scene.h \
    scene/interface.h \
    objects/scene_object.h \
    errors/primitives.h \
    errors/objects.h \
    objects/simple_object.h \
    objects/leg.h \
    objects/camera.h \
    objects/light_source.h \
    objects/visitors/object_visitor.h \
    visual/visualizer.h \
    visual/drawer.h \
    errors/visual.h \
    commands/base_command.h \
    managers/base_manager.h \
    errors/managers.h \
    managers/draw.h \
    objects/visitors/draw.h \
    managers/init_draw.h \
    commands/draw.h \
    commands/init_draw.h \
    commands/all.h \
    visual/projected_model.h \
    transform/transformator.h \
    transform/trans_action.h \
    managers/tranfrorm.h \
    commands/transform.h \
    objects/cue_ball.h \
    objects/plate.h \
    3d_prmitives/skirting.h \
    objects/rails.h \
    3d_prmitives/mplate.h \
    objects/composite_object.h \
    objects/table.h \
    updater/updater.h \
    updater/rail_contour.h \
    managers/update_mng.h \
    objects/visitors/update_visitor.h \
    commands/update_cmd.h \
    builder/builder.h \
    managers/build_mng.h \
    errors/builder_errors.h \
    commands/builder_cmd.h \
    faq_move.h \
    faq_light.h \
    faq_hit.h

FORMS += \
        mainwindow.ui \
    faq_move.ui \
    faq_light.ui \
    faq_hit.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
