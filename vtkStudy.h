#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_vtkStudy.h"

#include <vtkSphereSource.h>//该头文件包含了用于生成球体几何数据的类。
#include <vtkPolyDataMapper.h>//该头文件包含了用于将vtkPolyData数据映射为可视化对象的类。
#include "vtkActor.h"//该头文件包含了表示可视化对象的类，可以将vtkPolyDataMapper封装为一个可视化对象。
#include <vtkProperty.h>//该头文件包含了用于设置可视化对象属性（例如颜色、透明度等）的类。
#include "vtkRenderer.h"//该头文件包含了管理和渲染可视化对象的类，可以将多个vtkActor添加到vtkRenderer中进行渲染。
#include <vtkGenericOpenGLRenderWindow.h>//该头文件包含了与特定平台无关的OpenGL渲染窗口类，用于在不同的图形界面（如Qt）中显示渲染结果。


class vtkStudy : public QMainWindow
{
    Q_OBJECT

        std::vector<vtkSmartPointer<vtkSphereSource>> sphereSources;    //用于保存多个球体源对象

public:
    vtkStudy(QWidget* parent = nullptr);
    ~vtkStudy();

    void DrawSphere();//绘制球体

private:
    Ui::vtkStudyClass ui;
};
