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

        <p><b>El naranjo</b> es un árbol de tamaño mediano, de tres a cinco metros de altura, con copa redondeada y ramas regulares. Un solo tronco, derecho y cilíndrico, verdoso primero y gris después. Las ramas aparecen a un metro, poco más o menos, del suelo. Las hojas son perennes, medianas y alargadas, con base redondeada y terminadas en punta. Las flores aparecen en las axilas de las hojas, solitarias o en racimos.

		El naranjo puede reproducirse por germinación de una semilla, por trasplante de una estaca o por acodo, es decir, partiendo de una raíz. En cualquier caso ha de transcurrir un cierto tiempo en el vivero o plantel antes de pasar al huerto o naranjal
		</p>
    	
		<h2>Cuidados</h2>
		<h3>Clima</h3>
    	<xsl:value-of select="Cuidados/Clima"/>
    	<h3>Terreno</h3>
    	<xsl:value-of select="Cuidados/Terreno"/>
    	<h3>Plagas más comunes</h3>

    	<xsl:for-each select="Planta/Cuidados/Plagas">
    		<xsl:value-of select="Planta7Cuidados/Plagas/nombres"/>



    	</xsl:for-each>



       
    	

		  </xsl:if>
		</xsl:for-each>

	</xsl:template>
</xsl:stylesheet>