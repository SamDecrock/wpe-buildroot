
define BCM_REFSW_BUILD_NXSERVER
	$(TARGET_CONFIGURE_OPTS) \
	$(TARGET_MAKE_ENV) \
	$(BCM_REFSW_CONF_OPTS) \
	$(BCM_REFSW_MAKE_ENV) \
		$(MAKE) -C $(@D)/nexus/nxclient/server all \
			LIBDIR=${BCM_REFSW_BIN}
endef

ifeq ($(BR2_PACKAGE_BCM_REFSW_BUILD_NXCLIENT_EXAMPLES),y)
define BCM_REFSW_BUILD_NXCLIENT_EXAMPLES
	$(TARGET_CONFIGURE_OPTS) \
	$(TARGET_MAKE_ENV) \
	$(BCM_REFSW_CONF_OPTS) \
	$(BCM_REFSW_MAKE_ENV) \
		$(MAKE) -C $(@D)/nexus/nxclient/examples all \
			LIBDIR=${BCM_REFSW_BIN}
endef
endif

ifeq ($(BR2_PACKAGE_BCM_WESTON),y)
define BCM_REFSW_INSTALL_NXSERVER_INIT
endef
else
define BCM_REFSW_INSTALL_NXSERVER_INIT
	$(INSTALL) -D -m 755 package/bcm-refsw/S70nxserver $(TARGET_DIR)/etc/init.d/S70nxserver; \
	sed -i 's/%IRMODE%/${BCM_REFSW_IRMODE}/g' $(TARGET_DIR)/etc/init.d/S70nxserver;
endef
endif

define BCM_REFSW_INSTALL_NXSERVER
	$(INSTALL) -D $(BCM_REFSW_BIN)/libnxclient.so $(1)/usr/lib/libnxclient.so
	if [ "x$(BR2_PACKAGE_WPEFRAMEWORK_COMPOSITOR)" = "x" ]; then \
		$(INSTALL) -m 755 -D $(BCM_REFSW_BIN)/nxserver $(1)/usr/bin/nxserver; \
		$(BCM_REFSW_INSTALL_NXSERVER_INIT) \
	fi
endef

define BCM_REFSW_INSTALL_NXSERVER_DEV
	$(call BCM_REFSW_INSTALL_NXSERVER,$(STAGING_DIR))
	$(INSTALL) -m 755 -d $(STAGING_DIR)/usr/include/refsw
	$(INSTALL) -m 644 -D $(BCM_REFSW_BIN)/libnxserver.a $(STAGING_DIR)/usr/lib/libnxserver.a
	$(INSTALL) -m 644 $(BCM_REFSW_DIR)/nexus/nxclient/server/*.h $(STAGING_DIR)/usr/include/refsw/
	$(INSTALL) -m 644 $(BCM_REFSW_DIR)/nexus/nxclient/include/*.h $(STAGING_DIR)/usr/include/refsw/
endef

