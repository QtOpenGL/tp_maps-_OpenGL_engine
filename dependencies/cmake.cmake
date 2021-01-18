if(IOS)
  list(APPEND TP_LIBRARIES "-framework OpenGLES")
elseif(APPLE)
  list(APPEND TP_LIBRARIES "-framework OpenGL")
  list(APPEND TP_DEFINES "GL_SILENCE_DEPRECATION")
elseif(ANDROID)
  message("ANDROID_PLATFORM:${ANDROID_PLATFORM}")
  #android-16
  string(SUBSTRING "${ANDROID_PLATFORM}" 8 2 ANDROID_PLATFORM_API_VERSION)
  message("ANDROID_PLATFORM_API_VERSION:${ANDROID_PLATFORM_API_VERSION}")
  if(ANDROID_PLATFORM_API_VERSION LESS 18)
    list(APPEND TP_LIBRARIES "GLESv2")
  else()
    list(APPEND TP_LIBRARIES "GLESv3")
  endif()
elseif(WIN32)
  list(APPEND TP_LIBRARIES "glu32")  
  list(APPEND TP_LIBRARIES "glew32")  
  list(APPEND TP_LIBRARIES "opengl32")
elseif(USE_GL)
  list(APPEND TP_LIBRARIES "GL")
else()
  list(APPEND TP_LIBRARIES "OpenGL")
endif()
