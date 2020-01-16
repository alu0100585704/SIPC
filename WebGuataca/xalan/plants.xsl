<?xml version="1.0"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:output method="html" encoding="UTF-8"/>
<xsl:template match="/">
<html>
<head><title>Plantaciones</title>
</head>
<body>

<br/>
<li> Temperatura Mínima menor a 7 grados. Orden ascendente por nombre</li>
<li> En verde plantaciones de menos de 100 litros</li>
<li> Concatenación mes y dia</li>
<br/>
<br/>
<table width="100%" border="1">
  <THEAD>
           <TR>
                <TD width="25%"><B>Tipo</B></TD>
                <TD width="10%"><B>Litros</B></TD>
                <TD width="10%"><B>Temperatura máxima</B></TD>
               <TD width="10%"><B>Temperatura mínima</B></TD>  
               <TD width="10%"><B>Temporada / Dia</B></TD>            
               <TD width="10%"><B>Temporada / Mes</B></TD>            
             <TD width="10%"><B>Temporada</B></TD>             
          </TR>
   </THEAD> 
  <TBODY>
             <xsl:for-each select="Plantaciones/planta[Temperatura/min&lt;7]">
	      <xsl:sort order="ascending" select="@nombre"/> 
             <TR> 
             <xsl:if test="Litros&lt;100">
              <xsl:attribute name="bgcolor">#00FF00> </xsl:attribute>
             </xsl:if>
                  <TD width="35%"><xsl:value-of select="@nombre" /></TD>   
                  <TD width="15%"><xsl:value-of select="Litros" /></TD> 
                  <TD width="10%"><xsl:value-of select="Temperatura/max" /></TD>
                  <TD width="10%"><xsl:value-of select="Temperatura/min" /></TD>
                   <TD width="10%"><xsl:value-of select="temporada/dia" /></TD>                 
                   <TD width="10%"><xsl:value-of select="temporada/mes" /></TD>                 
                   <TD width="10%"><xsl:value-of select="concat(temporada/dia,' / ',temporada/mes)" /></TD>                 
               
            </TR>
            </xsl:for-each>
  </TBODY>
</table>

<br/>
<br/>
<li> Temperatura Mínima mayor o igual a 7 grados. Orden ascendente por nombre</li>
<li> En verde plantaciones de menos de 100 litros</li>
<li> Concatenación mes y dia</li>
<br/>
<br/>
<table width="100%" border="1">
  <THEAD>
           <TR>
                <TD width="25%"><B>Tipo</B></TD>
                <TD width="10%"><B>Litros</B></TD>
                <TD width="10%"><B>Temperatura máxima</B></TD>
               <TD width="10%"><B>Temperatura mínima</B></TD>
              <TD width="10%"><B>Temporada / Dia</B></TD>            
               <TD width="10%"><B>Temporada / Mes</B></TD> 
             <TD width="10%"><B>Temporada</B></TD>             
          </TR>
   </THEAD> 
	<TBODY>
             <xsl:for-each select="Plantaciones/planta[Temperatura/min&gt;6]">
	      <xsl:sort order="ascending" select="@nombre"/> 
             <TR> 
                   <xsl:if test="Litros&lt;100">
              <xsl:attribute name="bgcolor">#00FF00> </xsl:attribute>
             </xsl:if>
                  <TD width="35%"><xsl:value-of select="@nombre" /></TD>   
                  <TD width="15%"><xsl:value-of select="Litros" /></TD> 
                  <TD width="10%"><xsl:value-of select="Temperatura/max" /></TD>
                  <TD width="10%"><xsl:value-of select="Temperatura/min" /></TD>
                  <TD width="10%"><xsl:value-of select="temporada/dia" /></TD>                 
                   <TD width="10%"><xsl:value-of select="temporada/mes" /></TD>  
                  <TD width="10%"><xsl:value-of select="concat(temporada/dia,' / ',temporada/mes)" /></TD>                 
            </TR>
            </xsl:for-each>
  </TBODY>
</table>
</body>
</html>
</xsl:template>
</xsl:stylesheet>