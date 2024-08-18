#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VtkTest.h"

#include <vtkSphereSource.h>//该头文件包含了用于生成球体几何数据的类
#include <vtkPolyDataMapper.h>//该头文件包含了用于将vtkPolyData数据映射为可视化对象的类。
#include "vtkActor.h"//该头文件包含了表示可视化对象的类，可以将vtkPolyDataMapper封装为一个可视化对象。
#include <vtkProperty.h>//该头文件包含了用于设置可视化对象属性（例如颜色、透明度等）的类。
#include "vtkRenderer.h"//该头文件包含了管理和渲染可视化对象的类，可以将多个vtkActor添加到vtkRenderer中进行渲染。
#include <vtkGenericOpenGLRenderWindow.h>//该头文件包含了与特定平台无关的OpenGL渲染窗口类，用于在不同的图形界面（如Qt）中显示渲染结果。
#include <vtkTransformPolyDataFilter.h>//该头文件包含了用于对vtkPolyData应用变换操作的类。
#include <vtkTransform.h>//该头文件包含了表示几何变换的类，可以用于平移、旋转、缩放等操作。
#include <vtkAppendPolyData.h>//该头文件包含了用于将多个vtkPolyData数据合并为一个vtkPolyData数据的类。
#include <vtkParametricSpline.h>//该头文件包含了用于生成参数样条曲线几何数据的类。
#include <vtkParametricFunctionSource.h>//该头文件包含了用于计算参数化函数的几何数据的类，可以根据给定的参数化函数生成几何数据。
#include <vtkGeometryFilter.h>//该头文件包含了用于将任何vtkDataSet转换为vtkPolyData的类，可以将各种类型的几何数据转换为vtkPolyData进行后续处理和可视化。
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <IVtkTools_ShapeDataSource.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <vtkAutoInit.h>
#include <vtkRenderWindow.h>//绘制窗口
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRenderWindowInteractor.h>//交互机制类
#include <IGESControl_Reader.hxx> 
#include <STEPCAFControl_Reader.hxx>
#include <Bnd_Box.hxx>
#include <BRepBndLib.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <vtkEllipseArcSource.h>
#include <vtkCleanPolyData.h >
#include <vtkNew.h>
#include <vtkPoints.h>
#include <vtkCellArray.h>
#include <vtkBoundingBox.h>
#include <vtkAxesActor.h>
#include <BRepMesh_IncrementalMesh.hxx>
#include <vtkConeSource.h>//源数据
#include <vtkPolyDataReader.h>//vtk格式数据读取
#include <vtkCamera.h>//照相机
#include <vtkSmartPointer.h>
#include <vtkUnstructuredGridReader.h>
#include <vtkUnstructuredGrid.h>
#include <vtkPolyData.h>
#include "vtkVolume16Reader.h"
#include "vtkVolumeProperty.h"


class VtkTest : public QMainWindow
{
    //加入Q_OBJECT宏的作用:使得能用QT中的signal和slot机制，而且Q_OBJECT要放在类的最前面
    Q_OBJECT

    std::vector<vtkSmartPointer<vtkSphereSource>> sphereSources;    //用于保存多个球体源对象

public:
    VtkTest(QWidget *parent = nullptr);
    ~VtkTest();
    
private:
    Ui::VtkTestClass ui;
};
