<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0"
xmlns:xsl="http://www.w3.org/1999/XSL/Transform">

	<xsl:template match="/">
	  <html>
		  <head>
				<title> Guia de Plantacion</title>
				<meta charset="UTF-8"/>
		  </head>
		  <body>
		  	<xsl:apply-templates select="Plantaciones/Frutales"/>
		  	
		  </body>
	  </html>
	</xsl:template>

	<xsl:template match="Frutales">
		<h2>Guia de Plantacion de Arboles Frutales</h2>
		<xsl:for-each select="Planta">
			<xsl:if test="@NOMBRE='Naranjo'">
        <h1>Naranjo</h1>
        <p><img>
        <xsl:attribute name="src">
        		<xsl:value-of select="Imagen"/>
        	</xsl:attribute>
        </img>
      	</p>
      	<h2> Descripcion</h2>
      	<xsl:value-of select="Descripcion"/>
        
    	
		<h2>Cuidados</h2>
		<h3>Clima</h3>
    	<xsl:value-of select="Cuidados/Clima"/>
    	<h3>Terreno</h3>
    	<xsl:value-of select="Cuidados/Terreno"/>
    	<h3>Plagas más comunes</h3>

    	<xsl:for-each select="Cuidados/Plagas">
    		<h2><xsl:value-of select="@NOMBRE"/></h2>
    		<xsl:value-of select="Descripcion"/>
    	</xsl:for-each>

    	

</xsl:if>
</xsl:for-each>

	</xsl:template>
</xsl:stylesheet>