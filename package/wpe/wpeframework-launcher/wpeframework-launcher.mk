WPEFRAMEWORK_LAUNCHER_VERSION = 94e4d81cfdc4ac2e169ae95955e19ee8e98f2ea7
WPEFRAMEWORK_LAUNCHER_SITE_METHOD = git
WPEFRAMEWORK_LAUNCHER_SITE = git@github.com:WebPlatformForEmbedded/WPEPluginLauncher.git
WPEFRAMEWORK_LAUNCHER_INSTALL_STAGING = YES
WPEFRAMEWORK_LAUNCHER_DEPENDENCIES = wpeframework

WPEFRAMEWORK_LAUNCHER_CONF_OPTS += -DBUILD_REFERENCE=${WPEFRAMEWORK_LAUNCHER_VERSION}

$(eval $(cmake-package))

