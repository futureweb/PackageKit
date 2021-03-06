AM_CFLAGS = \
	$(PK_PLUGIN_CFLAGS) \
	$(SLACK_CFLAGS) \
	$(WARNINGFLAGS_C) \
	-DG_LOG_DOMAIN=\"PackageKit-Slackware\" \
	-DSYSCONFDIR=\""$(sysconfdir)"\" \
	-DLOCALSTATEDIR=\""$(localstatedir)"\" \
	-DLIBDIR=\""$(libdir)"\"

PK_GLIB2_LIBS =	\
	-lbz2 -lcurl \
	$(SQLITE_LIBS) \
	$(GLIB_LIBS) \
	$(top_builddir)/lib/packagekit-glib2/libpackagekit-glib2.la

pk_dependencies_SOURCES = \
	$(top_builddir)/src/pk-backend.c \
	$(top_builddir)/src/pk-shared.c \
	$(top_builddir)/src/pk-backend-job.c

plugindir = $(PK_PLUGIN_DIR)
plugin_LTLIBRARIES = libpk_backend_slack.la
libpk_backend_slack_la_SOURCES = \
	pk-backend-slack.c \
	slack-utils.c \
	slack-pkgtools.c \
	slack-slackpkg.c \
	slack-dl.c
libpk_backend_slack_la_LIBADD = \
	-lbz2 \
	$(PK_PLUGIN_LIBS) \
	${SLACK_LIBS}
libpk_backend_slack_la_LDFLAGS = -module -avoid-version
libpk_backend_slack_la_CFLAGS = $(AM_CFLAGS)

confdir = $(sysconfdir)/PackageKit
conf_in_files = Slackware.conf.in
conf_DATA = $(conf_in_files:.conf.in=.conf)

$(conf_DATA): $(conf_in_files) Makefile
	@sed -e "s|\@pkgmain\@|$(SLACK_PKGMAIN)|" $< > $@

databasedir = $(localstatedir)/cache/PackageKit/metadata
database_DATA =	metadata.db

check_PROGRAMS = \
	slack-slackpkg-test \
	slack-dl-test

slack_slackpkg_test_SOURCES = \
	slack-utils.c \
	slack-pkgtools.c \
	slack-slackpkg.c \
	$(pk_dependencies_SOURCES) \
	slack-slackpkg-test.c
slack_slackpkg_test_LDADD = $(PK_GLIB2_LIBS)
slack_slackpkg_test_CFLAGS = $(AM_CFLAGS)

slack_dl_test_SOURCES = \
	slack-utils.c \
	slack-pkgtools.c \
	slack-dl.c \
	$(pk_dependencies_SOURCES) \
	slack-dl-test.c
slack_dl_test_LDADD = $(PK_GLIB2_LIBS)
slack_dl_test_CFLAGS = $(AM_CFLAGS)

TESTS = $(check_PROGRAMS)

EXTRA_DIST = \
	$(conf_in_files) \
	$(database_DATA)

clean-local:
	rm -f *~

-include $(top_srcdir)/git.mk
