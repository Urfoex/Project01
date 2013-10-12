set( FONT_FILES
	LiberationMono-Regular.ttf
)

foreach( font ${FONT_FILES})
	message("-- INFO " "Copying ${font}")
	CONFIGURE_FILE(${font} ${CMAKE_CURRENT_BINARY_DIR}/ COPYONLY)
endforeach()
