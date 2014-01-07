#ifndef OPENGLDATA_H
#define OPENGLDATA_H

#include "scenegraphnode.h"
#include "textureblitter.h"
#include "qopenglwindow.h"
#include "geometry.h"


#include <QtGui/private/qopengltexturecache_p.h>
#include <QOpenGLFunctions>
#include <QPainter>
#include <QLinkedList>
#include <QtGui/QOpenGLShaderProgram>
#include <QtGui/QOpenGLContext>
#include <QtGui/QOpenGLFunctions>

#include <glm/glm.hpp>

class SceneGraphNode;
class OpenGLData
{
public:
    QOpenGLWindow *m_window;
    TextureBlitter *m_textureBlitter;
    QOpenGLTextureCache *m_textureCache;
    GLuint m_surface_fbo;
    QOpenGLShaderProgram *m_surfaceShader;
    SceneGraphNode *m_cameraNode;
    Geometry::Camera *m_camera;


    OpenGLData(QOpenGLWindow *window, SceneGraphNode *camera);
    ~OpenGLData();
    QImage makeBackgroundImage(const QString &fileName);

    void calculateVPMatrix();

    float ppcm();

    glm::mat4 viewMatrix() const;
    glm::mat4 projectionMatrix() const;
    glm::mat4 viewProjectionMatrix() const;

private:
    float m_ppcm;
    glm::mat4 m_viewMatrix, m_projectionMatrix, m_viewProjectionMatrix;


};

#endif // OPENGLDATA_H