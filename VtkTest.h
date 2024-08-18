#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VtkTest.h"

#include <vtkSphereSource.h>//��ͷ�ļ������������������弸�����ݵ���
#include <vtkPolyDataMapper.h>//��ͷ�ļ����������ڽ�vtkPolyData����ӳ��Ϊ���ӻ�������ࡣ
#include "vtkActor.h"//��ͷ�ļ������˱�ʾ���ӻ�������࣬���Խ�vtkPolyDataMapper��װΪһ�����ӻ�����
#include <vtkProperty.h>//��ͷ�ļ��������������ÿ��ӻ��������ԣ�������ɫ��͸���ȵȣ����ࡣ
#include "vtkRenderer.h"//��ͷ�ļ������˹������Ⱦ���ӻ�������࣬���Խ����vtkActor��ӵ�vtkRenderer�н�����Ⱦ��
#include <vtkGenericOpenGLRenderWindow.h>//��ͷ�ļ����������ض�ƽ̨�޹ص�OpenGL��Ⱦ�����࣬�����ڲ�ͬ��ͼ�ν��棨��Qt������ʾ��Ⱦ�����
#include <vtkTransformPolyDataFilter.h>//��ͷ�ļ����������ڶ�vtkPolyDataӦ�ñ任�������ࡣ
#include <vtkTransform.h>//��ͷ�ļ������˱�ʾ���α任���࣬��������ƽ�ơ���ת�����ŵȲ�����
#include <vtkAppendPolyData.h>//��ͷ�ļ����������ڽ����vtkPolyData���ݺϲ�Ϊһ��vtkPolyData���ݵ��ࡣ
#include <vtkParametricSpline.h>//��ͷ�ļ��������������ɲ����������߼������ݵ��ࡣ
#include <vtkParametricFunctionSource.h>//��ͷ�ļ����������ڼ�������������ļ������ݵ��࣬���Ը��ݸ����Ĳ������������ɼ������ݡ�
#include <vtkGeometryFilter.h>//��ͷ�ļ����������ڽ��κ�vtkDataSetת��ΪvtkPolyData���࣬���Խ��������͵ļ�������ת��ΪvtkPolyData���к�������Ϳ��ӻ���
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <IVtkTools_ShapeDataSource.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <vtkAutoInit.h>
#include <vtkRenderWindow.h>//���ƴ���
#include <vtkInteractorStyleTrackballCamera.h>
#include <vtkRenderWindowInteractor.h>//����������
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
#include <vtkConeSource.h>//Դ����
#include <vtkPolyDataReader.h>//vtk��ʽ���ݶ�ȡ
#include <vtkCamera.h>//�����
#include <vtkSmartPointer.h>
#include <vtkUnstructuredGridReader.h>
#include <vtkUnstructuredGrid.h>
#include <vtkPolyData.h>
#include "vtkVolume16Reader.h"
#include "vtkVolumeProperty.h"


class VtkTest : public QMainWindow
{
    //����Q_OBJECT�������:ʹ������QT�е�signal��slot���ƣ�����Q_OBJECTҪ���������ǰ��
    Q_OBJECT

    std::vector<vtkSmartPointer<vtkSphereSource>> sphereSources;    //���ڱ���������Դ����

public:
    VtkTest(QWidget *parent = nullptr);
    ~VtkTest();
    
private:
    Ui::VtkTestClass ui;
};
