# Create and install documentation files

kdoctools_create_handbook(index.docbook
    INSTALL_DESTINATION ${KDE_INSTALL_DOCBUNDLEDIR}/en
    SUBDIR kronometer)
kdoctools_create_manpage(man-kronometer.1.docbook
    1
    INSTALL_DESTINATION
    ${KDE_INSTALL_MANDIR})
