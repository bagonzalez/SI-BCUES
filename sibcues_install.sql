-- phpMyAdmin SQL Dump
-- version 2.11.7
-- http://www.phpmyadmin.net
--
-- Servidor: localhost
-- Tiempo de generación: 30-11-2009 a las 19:18:57
-- Versión del servidor: 5.0.86
-- Versión de PHP: 5.2.6

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Base de datos: `sibcues`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `actualizacioncatalogo`
--

CREATE TABLE IF NOT EXISTS `actualizacioncatalogo` (
  `idUsuario` int(11) default NULL,
  `idEspecificacion` int(11) default NULL,
  `fechaActualizacion` date default NULL,
  `horaActualizacion` time default NULL,
  `idActualizacion` int(11) NOT NULL default '0',
  PRIMARY KEY  (`idActualizacion`),
  KEY `FK_ModificaEspecificacion` (`idEspecificacion`),
  KEY `FK_RegistraActualizacion` (`idUsuario`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcar la base de datos para la tabla `actualizacioncatalogo`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `autor`
--

CREATE TABLE IF NOT EXISTS `autor` (
  `idAutor` int(11) NOT NULL auto_increment,
  `nombreAutor` varchar(50) default NULL,
  `apellidoAutor` varchar(35) default NULL,
  PRIMARY KEY  (`idAutor`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=20 ;

--
-- Volcar la base de datos para la tabla `autor`
--

INSERT INTO `autor` (`idAutor`, `nombreAutor`, `apellidoAutor`) VALUES
(12, 'OCEANO', ''),
(11, 'CONSEJO SUPERIOR UNIVERSITARIO', ''),
(13, 'ELMER EDGARDO ', 'TRINIDAD'),
(14, 'MANUEL DE JESUS', 'FORNOS'),
(15, 'IRIS', 'CHACON'),
(16, 'BORIS', 'MONTANO'),
(17, 'GABRIELA MARIA', 'CASTANEDA'),
(18, 'BRUNO', 'GONZALEZ'),
(19, 'ROBERTO', 'ORELLANA');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `bien`
--

CREATE TABLE IF NOT EXISTS `bien` (
  `idUsuario` int(11) default NULL,
  `idEspecificacion` int(11) NOT NULL default '0',
  `idInventario` int(11) default NULL,
  `fechaAdquisicion` date default NULL,
  `valor` float default NULL,
  `idBien` int(11) NOT NULL auto_increment,
  `idSector` int(11) default NULL,
  `estadoBien` enum('activo','descargado','trasladado') default NULL,
  `serial` varchar(20) default NULL,
  `tipoBien` enum('activofijo','matbibliografico') default NULL,
  `correlativo` varchar(4) NOT NULL default '',
  `idTitulo` int(11) NOT NULL default '0',
  `idAutor` int(11) default NULL,
  `idModelo` int(11) NOT NULL default '0',
  PRIMARY KEY  (`idEspecificacion`,`idBien`),
  KEY `FK_PerteneceInventario` (`idInventario`),
  KEY `FK_SeleccionaBien` (`idUsuario`),
  KEY `FK_asignado` (`idSector`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=6 ;

--
-- Volcar la base de datos para la tabla `bien`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `catalogo`
--

CREATE TABLE IF NOT EXISTS `catalogo` (
  `fechaUltimaActualizacion` date default NULL,
  `fechaCreacion` date default NULL,
  `idCatalogo` int(11) NOT NULL auto_increment,
  `idUnidad` int(11) default NULL,
  PRIMARY KEY  (`idCatalogo`),
  KEY `FK_UnidadPosee` (`idUnidad`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=7 ;

--
-- Volcar la base de datos para la tabla `catalogo`
--

INSERT INTO `catalogo` (`fechaUltimaActualizacion`, `fechaCreacion`, `idCatalogo`, `idUnidad`) VALUES
('2009-11-02', '2009-11-02', 6, 8);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `catalogoactivofijo`
--

CREATE TABLE IF NOT EXISTS `catalogoactivofijo` (
  `idCatalogoAF` int(11) NOT NULL auto_increment,
  PRIMARY KEY  (`idCatalogoAF`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=3 ;

--
-- Volcar la base de datos para la tabla `catalogoactivofijo`
--

INSERT INTO `catalogoactivofijo` (`idCatalogoAF`) VALUES
(1);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `clase`
--

CREATE TABLE IF NOT EXISTS `clase` (
  `idCatalogo` int(11) default NULL,
  `idCuenta` int(11) default NULL,
  `idClase` int(11) NOT NULL auto_increment,
  `nombreClase` varchar(10) default NULL,
  `idEspecifico` int(11) default NULL,
  PRIMARY KEY  (`idClase`),
  KEY `FK_Tiene_Asignada` (`idCatalogo`,`idCuenta`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=64 ;

--
-- Volcar la base de datos para la tabla `clase`
--

INSERT INTO `clase` (`idCatalogo`, `idCuenta`, `idClase`, `nombreClase`, `idEspecifico`) VALUES
(6, 31, 49, '040', 19),
(6, 30, 48, '004', 20),
(6, 29, 47, '003', 20),
(6, 28, 46, '002', 20),
(6, 27, 45, '001', 19),
(6, 32, 50, '080', 22),
(6, 33, 51, '082', 19),
(6, 34, 52, '083', 19),
(6, 35, 53, '084', 19),
(6, 36, 54, '085', 19),
(6, 37, 55, '001', 21),
(6, 38, 56, '002', 20),
(6, 39, 57, '001', 23),
(6, 40, 58, '002', 23),
(6, 41, 59, '003', 23),
(6, 42, 60, '004', 23),
(6, 43, 61, '005', 23),
(6, 44, 62, '006', 23),
(6, 45, 63, '007', 23);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `cuenta`
--

CREATE TABLE IF NOT EXISTS `cuenta` (
  `idCatalogo` int(11) NOT NULL default '0',
  `debe` float default NULL,
  `haber` float default NULL,
  `codigoCuenta` int(11) default NULL,
  `nombreCuenta` varchar(50) default NULL,
  `descripcion` varchar(150) default NULL,
  `cuentaSaldada` tinyint(1) default NULL,
  `idCuenta` int(11) NOT NULL auto_increment,
  `Cue_idCatalogo` int(11) default NULL,
  `Cue_idCuenta` int(11) default NULL,
  `tipoCuenta` enum('rubro','categoria','cuenta') default NULL,
  PRIMARY KEY  (`idCatalogo`,`idCuenta`),
  KEY `FK_Referencia` (`Cue_idCatalogo`,`Cue_idCuenta`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=44 ;

--
-- Volcar la base de datos para la tabla `cuenta`
--

INSERT INTO `cuenta` (`idCatalogo`, `debe`, `haber`, `codigoCuenta`, `nombreCuenta`, `descripcion`, `cuentaSaldada`, `idCuenta`, `Cue_idCatalogo`, `Cue_idCuenta`, `tipoCuenta`) VALUES
(6, 0, NULL, 1, 'Activos', 'Almacena los activos de la empresa', NULL, 1, NULL, NULL, 'rubro'),
(6, NULL, NULL, 2, 'Pasivos', 'Almacena los pasivos de la empresa', NULL, 2, NULL, NULL, 'rubro'),
(6, 0, 0, 3, 'Capital', 'Capital de la unidad', NULL, 4, NULL, NULL, 'rubro'),
(6, 0, 0, 4, 'Ingresos', 'Ingresos de la unidad', NULL, 5, NULL, NULL, 'rubro'),
(6, 0, 0, 5, 'Gastos', 'Gastos de la unidad', NULL, 6, NULL, NULL, 'rubro'),
(6, 0, 0, 11, 'Caja', 'Caja', NULL, 7, NULL, 1, 'categoria'),
(6, 0, 0, 12, 'Inventario', 'Inventario', NULL, 8, NULL, 1, 'categoria'),
(6, 0, 0, 12020, 'Inmuebles', 'Inmuebles', NULL, 9, NULL, 8, 'categoria'),
(6, 0, 0, 12030, 'Instalaciones', 'Instalaciones', NULL, 10, NULL, 8, 'categoria'),
(6, 0, 0, 12040, 'Mobiliario y equipo de Oficina', 'equipos', NULL, 11, NULL, 8, 'categoria'),
(6, 0, 0, 12050, 'Mobiliario y equipo de enseñanza', 'Guarda un consolidado de los mobiliarios para impartir  clases', NULL, 12, NULL, 8, 'categoria'),
(6, 0, 0, 12060, 'Mobiliario para servicios', 'Servicios varios', NULL, 13, NULL, 8, 'categoria'),
(6, 0, 0, 12070, 'Maquinaria y equipo', 'Lleva la administracion de material y equipo', NULL, 14, NULL, 8, 'categoria'),
(6, 0, 0, 12080, 'Equipo de Transporte', 'Equipo de Transporte', NULL, 15, NULL, 8, 'categoria'),
(6, 0, 0, 12090, 'Material Bibliografico', 'Material Bibliografico', NULL, 16, NULL, 8, 'categoria'),
(6, 0, 0, 51, 'Inversiones en Activos Fijos', 'Inversiones en Activos Fijos', NULL, 18, NULL, 6, 'categoria'),
(6, 0, 0, 51001, 'Mobiliario', 'Mobiliario', NULL, 19, NULL, 18, 'cuenta'),
(6, 0, 0, 51002, 'Maquinaria y Equipos', 'Maquinaria y Equipos', NULL, 20, NULL, 18, 'cuenta'),
(6, 0, 0, 51003, 'Equipos Médicos y de Laboratorio', 'Equipos Médicos y de Laboratorio', NULL, 21, NULL, 18, 'cuenta'),
(6, 0, 0, 51004, 'Equipos Informáticos', 'Equipos Informáticos', NULL, 22, NULL, 18, 'cuenta'),
(6, 0, 0, 51005, 'Libros y Colecciones', 'Libros y Colecciones', NULL, 23, NULL, 18, 'cuenta'),
(6, 0, 0, 11001, 'Efectivo', 'Realice operaciones diarias.', NULL, 26, NULL, 7, 'cuenta'),
(6, 0, 0, 0, '12030-001', 'AIRE ACONDICIONADO ', NULL, 27, NULL, 10, 'cuenta'),
(6, 0, 0, 0, '12030-002', 'ANTENAS PARABOLICAS', NULL, 28, NULL, 10, 'cuenta'),
(6, 0, 0, 0, '12030-003', 'ACONDICIONADOR DE SEÑALES', NULL, 29, NULL, 10, 'cuenta'),
(6, 0, 0, 0, '12040-004', 'ASCENSORES', NULL, 30, NULL, 11, 'cuenta'),
(6, 0, 0, 0, '12040-040', 'CAFETERA', NULL, 31, NULL, 11, 'cuenta'),
(6, 0, 0, 0, '12040-080', 'EQUIPO DE COMPUTACION CPU/TECLADO/MOUSE/IMPRESOR', NULL, 32, NULL, 11, 'cuenta'),
(6, 0, 0, 0, '12040-082', 'ESCRITORIO TIPO CATEDRA', NULL, 33, NULL, 11, 'cuenta'),
(6, 0, 0, 0, '12040-083', 'ESCRITORIO TIPO EJECUTIVO', NULL, 34, NULL, 11, 'cuenta'),
(6, 0, 0, 0, '12040-084', 'ESCRITORIO TIPO EJECUTIVO', NULL, 35, NULL, 11, 'cuenta'),
(6, 0, 0, 0, '12040-085', 'ESCRITORIO TIPO SECRETARIA', NULL, 36, NULL, 11, 'cuenta'),
(6, 0, 0, 0, '12080-001', 'AUTOBUSES', NULL, 37, NULL, 15, 'cuenta'),
(6, 0, 0, 0, '12080-002', 'AUTOMOBILES', NULL, 38, NULL, 15, 'cuenta'),
(6, 0, 0, 0, '12090-001', 'BOLETINES', NULL, 39, NULL, 16, 'cuenta'),
(6, 0, 0, 0, '12090-002', 'ENCICLOPEDIAS', NULL, 40, NULL, 16, 'cuenta'),
(6, 0, 0, 0, '12090-003', 'FOLLETOS', NULL, 41, NULL, 16, 'cuenta'),
(6, 0, 0, 0, '12090-004', 'LIBROS', NULL, 42, NULL, 16, 'cuenta'),
(6, 0, 0, 0, '12090-005', 'REVISTAS', NULL, 43, NULL, 16, 'cuenta'),
(6, 0, 0, 0, '12090-006', 'TESIS', NULL, 44, NULL, 16, 'cuenta'),
(6, 0, 0, 0, '12090-007', 'MANUALES', NULL, 45, NULL, 16, 'cuenta');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `descargobienes`
--

CREATE TABLE IF NOT EXISTS `descargobienes` (
  `idDescargo` int(11) NOT NULL auto_increment,
  `fechaDescargo` date default NULL,
  `horaDescargo` time default NULL,
  `unidadSolicitante` int(11) default NULL,
  `observaciones` varchar(150) default NULL,
  `motivoDescargo` varchar(150) default NULL,
  `tipoBienDescargo` enum('activofijo','matbibliografico') default NULL,
  PRIMARY KEY  (`idDescargo`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=19 ;

--
-- Volcar la base de datos para la tabla `descargobienes`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `especactivofijo`
--

CREATE TABLE IF NOT EXISTS `especactivofijo` (
  `descripcion` varchar(60) default NULL,
  `idEspecAF` int(11) NOT NULL auto_increment,
  PRIMARY KEY  (`idEspecAF`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=31 ;

--
-- Volcar la base de datos para la tabla `especactivofijo`
--

INSERT INTO `especactivofijo` (`descripcion`, `idEspecAF`) VALUES
('ANTENAS PARABOLICAS', 20),
('AIRE ACONDICIONADO ', 19),
('ACONDICIONADOR DE SEÑALES', 21),
('ASCENSORES', 22),
('CAFETERA', 23),
('EQUIPO DE COMPUTACION CPU/TECLADO/MOUSE/IMPRESOR', 24),
('ESCRITORIO TIPO CATEDRA', 25),
('ESCRITORIO TIPO EJECUTIVO', 26),
('ESCRITORIO TIPO EJECUTIVO', 27),
('ESCRITORIO TIPO SECRETARIA', 28),
('AUTOBUSES', 29),
('AUTOMOBILES', 30);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `especificacionbien`
--

CREATE TABLE IF NOT EXISTS `especificacionbien` (
  `idEspecificacion` int(11) NOT NULL auto_increment,
  `idEspecBiblio` int(11) default NULL,
  `idEspecAF` int(11) default NULL,
  `idCatalogoAF` int(11) default NULL,
  `idClase` int(11) default NULL,
  PRIMARY KEY  (`idEspecificacion`),
  KEY `FK_HeredaEspecAFijo` (`idEspecAF`),
  KEY `FK_HeredaEspecMatBiblio` (`idEspecBiblio`),
  KEY `FK_PerteneceCatalogoAFijo` (`idCatalogoAF`),
  KEY `FK_TieneAsignadaClase` (`idClase`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=55 ;

--
-- Volcar la base de datos para la tabla `especificacionbien`
--

INSERT INTO `especificacionbien` (`idEspecificacion`, `idEspecBiblio`, `idEspecAF`, `idCatalogoAF`, `idClase`) VALUES
(40, NULL, 23, 1, 49),
(39, NULL, 22, 1, 48),
(38, NULL, 21, 1, 47),
(37, NULL, 20, 1, 46),
(36, NULL, 19, 1, 45),
(41, NULL, 24, 1, 50),
(42, NULL, 25, 1, 51),
(43, NULL, 26, 1, 52),
(44, NULL, 27, 1, 53),
(45, NULL, 28, 1, 54),
(46, NULL, 29, 1, 55),
(47, NULL, 30, 1, 56),
(48, 9, NULL, 1, 57),
(49, 10, NULL, 1, 58),
(50, 11, NULL, 1, 59),
(51, 12, NULL, 1, 60),
(52, 13, NULL, 1, 61),
(53, 14, NULL, 1, 62),
(54, 15, NULL, 1, 63);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `especmaterialbibliografico`
--

CREATE TABLE IF NOT EXISTS `especmaterialbibliografico` (
  `idEspecBiblio` int(11) NOT NULL auto_increment,
  `descripcion` varchar(35) default NULL,
  PRIMARY KEY  (`idEspecBiblio`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=16 ;

--
-- Volcar la base de datos para la tabla `especmaterialbibliografico`
--

INSERT INTO `especmaterialbibliografico` (`idEspecBiblio`, `descripcion`) VALUES
(10, 'ENCICLOPEDIAS'),
(9, 'BOLETINES'),
(11, 'FOLLETOS'),
(12, 'LIBROS'),
(13, 'REVISTAS'),
(14, 'TESIS'),
(15, 'MANUALES');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `fabricante`
--

CREATE TABLE IF NOT EXISTS `fabricante` (
  `idFabricante` int(11) NOT NULL auto_increment,
  `idEspecAF` int(11) default NULL,
  `marca` varchar(30) default NULL,
  PRIMARY KEY  (`idFabricante`),
  KEY `FK_PerteneceFabricante` (`idEspecAF`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=37 ;

--
-- Volcar la base de datos para la tabla `fabricante`
--

INSERT INTO `fabricante` (`idFabricante`, `idEspecAF`, `marca`) VALUES
(31, 25, 'SIMAN'),
(30, 24, 'ACER'),
(29, 24, 'COMPAC'),
(28, 24, 'HP'),
(27, 23, 'ULTRASONIC'),
(26, 22, 'ALIBABA'),
(25, 21, 'CISCO'),
(24, 20, 'SATTELITTE'),
(23, 19, 'ENFRIO'),
(32, 26, 'SIMAN'),
(33, 27, 'SIMAN'),
(34, 28, 'SIMAN'),
(35, 29, 'BLUEBIRD'),
(36, 30, 'TOYOTA');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `ingresobienes`
--

CREATE TABLE IF NOT EXISTS `ingresobienes` (
  `idIngreso` int(11) NOT NULL auto_increment,
  `idProveedor` int(11) default NULL,
  `fechaIngreso` date default NULL,
  `cefNo` varchar(15) default NULL,
  `facturaNo` varchar(15) default NULL,
  `fechaFactura` date default NULL,
  `acuerdoCSU_NO` varchar(15) default NULL,
  `fechaAcuerdo` date default NULL,
  `fuenteIngreso` enum('fondogeneral','fondospropios','donado') default NULL,
  `observaciones` varchar(150) default NULL,
  `tipoBienIngreso` enum('matbibliografico','activofijo') default NULL,
  `horaIngreso` time default NULL,
  PRIMARY KEY  (`idIngreso`),
  KEY `FK_Provee` (`idProveedor`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=43 ;

--
-- Volcar la base de datos para la tabla `ingresobienes`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `ingresoclasecatalogo`
--

CREATE TABLE IF NOT EXISTS `ingresoclasecatalogo` (
  `idUsuario` int(11) default NULL,
  `fechaIngreso` date default NULL,
  `horaIngreso` time default NULL,
  `idIngreso` int(11) NOT NULL auto_increment,
  `idEspecificacion` int(11) default NULL,
  PRIMARY KEY  (`idIngreso`),
  KEY `FK_RealizaIngreso` (`idUsuario`),
  KEY `FK_RegistraIngreso` (`idEspecificacion`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=62 ;

--
-- Volcar la base de datos para la tabla `ingresoclasecatalogo`
--

INSERT INTO `ingresoclasecatalogo` (`idUsuario`, `fechaIngreso`, `horaIngreso`, `idIngreso`, `idEspecificacion`) VALUES
(22, '2009-11-30', '18:56:00', 47, NULL),
(22, '2009-11-30', '18:51:00', 46, NULL),
(22, '2009-11-30', '18:49:00', 45, NULL),
(22, '2009-11-30', '18:48:00', 44, NULL),
(22, '2009-11-30', '18:46:00', 43, NULL),
(22, '2009-11-30', '18:57:00', 48, NULL),
(22, '2009-11-30', '19:00:00', 49, NULL),
(22, '2009-11-30', '19:01:00', 50, NULL),
(22, '2009-11-30', '19:04:00', 51, NULL),
(22, '2009-11-30', '19:04:00', 52, NULL),
(22, '2009-11-30', '19:06:00', 53, NULL),
(22, '2009-11-30', '19:08:00', 54, NULL),
(22, '2009-11-30', '19:09:00', 55, NULL),
(22, '2009-11-30', '19:10:00', 56, NULL),
(22, '2009-11-30', '19:11:00', 57, NULL),
(22, '2009-11-30', '19:13:00', 58, NULL),
(22, '2009-11-30', '19:13:00', 59, NULL),
(22, '2009-11-30', '19:14:00', 60, NULL),
(22, '2009-11-30', '19:16:00', 61, NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `inventarioactivofijo`
--

CREATE TABLE IF NOT EXISTS `inventarioactivofijo` (
  `idInventario` int(11) NOT NULL auto_increment,
  `idUnidad` int(11) default NULL,
  PRIMARY KEY  (`idInventario`),
  KEY `FK_PerteneceAFUnidad` (`idUnidad`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Volcar la base de datos para la tabla `inventarioactivofijo`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `lineadescargo`
--

CREATE TABLE IF NOT EXISTS `lineadescargo` (
  `idEspecificacion` int(11) default NULL,
  `idBien` int(11) default NULL,
  `idDescargo` int(11) default NULL,
  KEY `FK_Descarga` (`idEspecificacion`,`idBien`),
  KEY `FK_ModificaBien` (`idDescargo`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcar la base de datos para la tabla `lineadescargo`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `lineadetransaccion`
--

CREATE TABLE IF NOT EXISTS `lineadetransaccion` (
  `idCatalogo` int(11) NOT NULL default '0',
  `idCuenta` int(11) NOT NULL default '0',
  `idTransaccion` int(11) NOT NULL default '0',
  `importe` float default NULL,
  `cargo` tinyint(1) default NULL,
  PRIMARY KEY  (`idCatalogo`,`idCuenta`,`idTransaccion`),
  KEY `FK_PerteneceTransaccion` (`idTransaccion`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcar la base de datos para la tabla `lineadetransaccion`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `lineadevariacion`
--

CREATE TABLE IF NOT EXISTS `lineadevariacion` (
  `idCatalogo` int(11) default NULL,
  `idCuenta` int(11) default NULL,
  `idEspecificacion` int(11) default NULL,
  `IdLineaVariacion` char(11) collate utf8_spanish2_ci default NULL,
  `PresupuestoOtorgado` float default NULL,
  `Razonamiento` varchar(75) collate utf8_spanish2_ci default NULL,
  `PresupuestoSolicitado` float default NULL,
  KEY `FK_Reference_2` (`idCatalogo`,`idCuenta`),
  KEY `FK_Reference_4` (`idEspecificacion`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish2_ci;

--
-- Volcar la base de datos para la tabla `lineadevariacion`
--

INSERT INTO `lineadevariacion` (`idCatalogo`, `idCuenta`, `idEspecificacion`, `IdLineaVariacion`, `PresupuestoOtorgado`, `Razonamiento`, `PresupuestoSolicitado`) VALUES
(NULL, 61107, 2010, '0_2010', 4500, 'se obtuvo mayor presupuesto devido a negciaciones', 2320),
(NULL, 61104, 2010, '1_2010', 2345, '---', 674),
(NULL, 61101, 2010, '2_2010', 676, '---', 123),
(NULL, 61103, 2010, '3_2010', 787, '---', 456),
(NULL, 51101, 2010, '4_2010', 7878, '---', 2355),
(NULL, 51104, 2010, '5_2010', 2343, '---', 567),
(NULL, 51105, 2010, '6_2010', 343, '---', 7889),
(NULL, 51107, 2010, '7_2010', 56, '---', 3345),
(NULL, 51401, 2010, '8_2010', 56767, '---', 4566),
(NULL, 51501, 2010, '9_2010', 4322, '---', 6778),
(NULL, 51601, 2010, '10_2010', 343, '---', 678),
(NULL, 51999, 2010, '11_2010', 3423, '---', 7899),
(NULL, 54101, 2010, '12_2010', 5466, '---', 34354),
(NULL, 54104, 2010, '13_2010', 563, '---', 5656),
(NULL, 54105, 2010, '14_2010', 4562, '---', 566),
(NULL, 54106, 2010, '15_2010', 455, '---', 66),
(NULL, 54107, 2010, '16_2010', 3456, '---', 657),
(NULL, 54108, 2010, '17_2010', 4566, '---', 56),
(NULL, 54112, 2010, '18_2010', 5667, '---', 65),
(NULL, 54113, 2010, '19_2010', 3545, '---', 55),
(NULL, 54114, 2010, '20_2010', 6777, '---', 3232),
(NULL, 54115, 2010, '21_2010', 8, '---', 45600),
(NULL, 54116, 2010, '22_2010', 8, '---', 36789),
(NULL, 54118, 2010, '23_2010', 8, '---', 2344),
(NULL, 54119, 2010, '24_2010', 8, '---', 454),
(NULL, 54199, 2010, '25_2010', 8, '---', 455),
(NULL, 54301, 2010, '26_2010', 88, '---', 6767),
(NULL, 54305, 2010, '27_2010', 8, '---', 5456),
(NULL, 54304, 2010, '28_2010', 8, '---', 676),
(NULL, 54307, 2010, '29_2010', 88, '---', 675),
(NULL, 54313, 2010, '30_2010', 8, '---', 354),
(NULL, 54399, 2010, '31_2010', 8, '---', 5657),
(NULL, 54402, 2010, '32_2010', 88, '---', 768),
(NULL, 54599, 2010, '33_2010', 8, '---', 4342),
(NULL, 54505, 2010, '34_2010', 8, '---', 234),
(NULL, 55508, 2010, '35_2010', 8, '---', 5656),
(NULL, 56305, 2010, '36_2010', 88, '---', 565),
(NULL, 61107, 2010, '0_2010', 4500, 'se obtuvo mayor presupuesto devido a negciaciones', 2320),
(NULL, 61104, 2010, '1_2010', 2345, '---', 674),
(NULL, 61101, 2010, '2_2010', 676, '---', 123),
(NULL, 61103, 2010, '3_2010', 787, '---', 456),
(NULL, 51101, 2010, '4_2010', 7878, '---', 2355),
(NULL, 51104, 2010, '5_2010', 2343, '---', 567),
(NULL, 51105, 2010, '6_2010', 343, '---', 7889),
(NULL, 51107, 2010, '7_2010', 56, '---', 3345),
(NULL, 51401, 2010, '8_2010', 56767, '---', 4566),
(NULL, 51501, 2010, '9_2010', 4322, '---', 6778),
(NULL, 51601, 2010, '10_2010', 343, '---', 678),
(NULL, 51999, 2010, '11_2010', 3423, '---', 7899),
(NULL, 54101, 2010, '12_2010', 5466, '---', 34354),
(NULL, 54104, 2010, '13_2010', 563, '---', 5656),
(NULL, 54105, 2010, '14_2010', 4562, '---', 566),
(NULL, 54106, 2010, '15_2010', 455, '---', 66),
(NULL, 54107, 2010, '16_2010', 3456, '---', 657),
(NULL, 54108, 2010, '17_2010', 4566, '---', 56),
(NULL, 54112, 2010, '18_2010', 5667, '---', 65),
(NULL, 54113, 2010, '19_2010', 3545, '---', 55),
(NULL, 54114, 2010, '20_2010', 6777, '---', 3232),
(NULL, 54115, 2010, '21_2010', 8, '---', 45600),
(NULL, 54116, 2010, '22_2010', 8, '---', 36789),
(NULL, 54118, 2010, '23_2010', 8, '---', 2344),
(NULL, 54119, 2010, '24_2010', 8, '---', 454),
(NULL, 54199, 2010, '25_2010', 8, '---', 455),
(NULL, 54301, 2010, '26_2010', 88, '---', 6767),
(NULL, 54305, 2010, '27_2010', 8, '---', 5456),
(NULL, 54304, 2010, '28_2010', 8, '---', 676),
(NULL, 54307, 2010, '29_2010', 88, '---', 675),
(NULL, 54313, 2010, '30_2010', 8, '---', 354),
(NULL, 54399, 2010, '31_2010', 8, '---', 5657),
(NULL, 54402, 2010, '32_2010', 88, '---', 768),
(NULL, 54599, 2010, '33_2010', 8, '---', 4342),
(NULL, 54505, 2010, '34_2010', 8, '---', 234),
(NULL, 55508, 2010, '35_2010', 8, '---', 5656),
(NULL, 56305, 2010, '36_2010', 88, '---', 565);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `lineaingreso`
--

CREATE TABLE IF NOT EXISTS `lineaingreso` (
  `idEspecificacion` int(11) default NULL,
  `idBien` int(11) default NULL,
  `idIngreso` int(11) default NULL,
  KEY `FK_IngresaBien` (`idEspecificacion`,`idBien`),
  KEY `FK_IngresaBienes` (`idIngreso`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcar la base de datos para la tabla `lineaingreso`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `lineatraslado`
--

CREATE TABLE IF NOT EXISTS `lineatraslado` (
  `idEspecificacion` int(11) default NULL,
  `idBien` int(11) default NULL,
  `idTraslado` int(11) default NULL,
  KEY `FK_TasladoBien` (`idTraslado`),
  KEY `FK_TrasladaBien` (`idEspecificacion`,`idBien`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcar la base de datos para la tabla `lineatraslado`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `modelo`
--

CREATE TABLE IF NOT EXISTS `modelo` (
  `idModelo` int(11) NOT NULL auto_increment,
  `idFabricante` int(11) default NULL,
  `modelo` varchar(15) default NULL,
  PRIMARY KEY  (`idModelo`),
  UNIQUE KEY `modelo` (`modelo`),
  KEY `FK_PerteneceA` (`idFabricante`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=40 ;

--
-- Volcar la base de datos para la tabla `modelo`
--

INSERT INTO `modelo` (`idModelo`, `idFabricante`, `modelo`) VALUES
(28, 25, '2543'),
(27, 24, 'ST-001'),
(26, 23, 'EN-002'),
(29, 26, 'ALI-01'),
(30, 27, '5001'),
(31, 28, 'HP001'),
(32, 29, 'COM2009'),
(33, 30, 'ASPONE'),
(34, 31, 'RUSTICIO'),
(35, 32, 'EJECUTIVO'),
(36, 33, 'PRESIDENTE'),
(37, 34, 'SECRETARIA'),
(38, 35, 'BB010'),
(39, 36, 'TOY-001');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `periodocontable`
--

CREATE TABLE IF NOT EXISTS `periodocontable` (
  `fechaInicio` date default NULL,
  `fechaFin` date default NULL,
  `idPeriodo` int(11) NOT NULL auto_increment,
  PRIMARY KEY  (`idPeriodo`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

--
-- Volcar la base de datos para la tabla `periodocontable`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `proveedor`
--

CREATE TABLE IF NOT EXISTS `proveedor` (
  `idProveedor` int(11) NOT NULL auto_increment,
  `nombreProveedor` varchar(50) default NULL,
  PRIMARY KEY  (`idProveedor`),
  UNIQUE KEY `nombreProveedor` (`nombreProveedor`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Volcar la base de datos para la tabla `proveedor`
--

INSERT INTO `proveedor` (`idProveedor`, `nombreProveedor`) VALUES
(1, 'RAF, S.A. DE C.V.');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `sectores`
--

CREATE TABLE IF NOT EXISTS `sectores` (
  `idSector` int(11) NOT NULL auto_increment,
  `descripcionSector` varchar(50) default NULL,
  PRIMARY KEY  (`idSector`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;

--
-- Volcar la base de datos para la tabla `sectores`
--

INSERT INTO `sectores` (`idSector`, `descripcionSector`) VALUES
(1, 'Dirección'),
(2, 'Administración'),
(3, 'Sistemas'),
(4, 'Digitalización'),
(5, 'Procesos Técnicos'),
(6, 'Circulación'),
(7, 'Referencia'),
(8, 'Internet'),
(9, 'Hemeroteca/Tesario');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `titulo`
--

CREATE TABLE IF NOT EXISTS `titulo` (
  `idAutor` int(11) NOT NULL default '0',
  `titulo` varchar(85) default NULL,
  `idTitulo` int(11) NOT NULL auto_increment,
  `idEspecBiblio` int(11) default NULL,
  `isbn` varchar(25) default NULL,
  `anioPublicacion` int(10) unsigned default NULL,
  `edicion` int(11) default NULL,
  PRIMARY KEY  (`idAutor`,`idTitulo`),
  UNIQUE KEY `isbn` (`isbn`),
  KEY `FK_tieneAsignadoTitulo` (`idEspecBiblio`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Volcar la base de datos para la tabla `titulo`
--

INSERT INTO `titulo` (`idAutor`, `titulo`, `idTitulo`, `idEspecBiblio`, `isbn`, `anioPublicacion`, `edicion`) VALUES
(13, 'ANALISIS FINANCIEROS DE LAS PYMES', 1, 11, '18372-2', NULL, NULL),
(12, 'OCEANO UNO COLOR', 1, 10, '1922-22', NULL, NULL),
(11, 'EL UNIVERSITARIO', 1, 9, '12-22', NULL, NULL),
(14, 'ADMINISTRACION FINANCIERA I', 1, 12, '976-99923-70-42-1', NULL, NULL),
(15, 'LA MUJER MODERNA', 1, 13, '18272-221', NULL, NULL),
(16, 'SISTEMA DE INFORMACION GEOREFERENCIADO', 1, 14, '', NULL, NULL);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `transaccion`
--

CREATE TABLE IF NOT EXISTS `transaccion` (
  `fechaTransaccion` date default NULL,
  `horaTransaccion` time default NULL,
  `codigoTransaccion` int(11) default NULL,
  `tipotransaccion` int(11) default NULL,
  `periodo` int(11) default NULL,
  `idTransaccion` int(11) NOT NULL default '0',
  `idPeriodo` int(11) default NULL,
  PRIMARY KEY  (`idTransaccion`),
  KEY `FK_PertenecePeriodo` (`idPeriodo`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Volcar la base de datos para la tabla `transaccion`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `trasladobienes`
--

CREATE TABLE IF NOT EXISTS `trasladobienes` (
  `idTraslado` int(11) NOT NULL auto_increment,
  `unidadEntrega` int(11) default NULL,
  `unidadRecibe` int(11) default NULL,
  `tipoTraslado` enum('temporal','definitivo') default NULL,
  `tipoBienTraslado` enum('matbibliografico','activofijo') default NULL,
  `fechaTraslado` date default NULL,
  `horaTraslado` time default NULL,
  `observaciones` varchar(150) character set utf8 collate utf8_spanish2_ci default NULL,
  PRIMARY KEY  (`idTraslado`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Volcar la base de datos para la tabla `trasladobienes`
--


-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `unidad`
--

CREATE TABLE IF NOT EXISTS `unidad` (
  `idUnidadP1` varchar(5) NOT NULL default '',
  `idUnidadP2` varchar(5) NOT NULL default '',
  `nombreUnidad` varchar(35) default NULL,
  `idUnidad` int(11) NOT NULL auto_increment,
  PRIMARY KEY  (`idUnidad`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;

--
-- Volcar la base de datos para la tabla `unidad`
--

INSERT INTO `unidad` (`idUnidadP1`, `idUnidadP2`, `nombreUnidad`, `idUnidad`) VALUES
('201', '123', 'Biblioteca Ingenieria', 9),
('200', '001', 'Biblioteca Central', 8);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuario`
--

CREATE TABLE IF NOT EXISTS `usuario` (
  `nombre` varchar(30) default NULL,
  `apellido` varchar(30) default NULL,
  `login` varchar(15) default NULL,
  `contrasenia` varchar(32) default NULL,
  `idUsuario` int(11) NOT NULL auto_increment,
  `idUnidad` int(11) default NULL,
  `rol` enum('tecnico','administrador','contador') default NULL,
  PRIMARY KEY  (`idUsuario`),
  KEY `FK_perteneceUnidad` (`idUnidad`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=24 ;

--
-- Volcar la base de datos para la tabla `usuario`
--

INSERT INTO `usuario` (`nombre`, `apellido`, `login`, `contrasenia`, `idUsuario`, `idUnidad`, `rol`) VALUES
('Bruno ', 'Gonzalez', 'bruno2d', '8a844cdbd990ceb7c509fb668821d73b', 22, 8, 'administrador'),
('Jotam Jr.', 'Trejo', 'jotamjr', '85f7a7ea5b71861ca46a2c2e89916af1', 21, 8, 'administrador'),
('Administrador', ' ', 'admin', '21232f297a57a5a743894a0e4a801fc3', 23, 8, 'administrador');

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `variacionpresupuestaria`
--

CREATE TABLE IF NOT EXISTS `variacionpresupuestaria` (
  `idEspecificacion` int(11) NOT NULL,
  `FuenteFinanciamiento` enum('0201 Fondo General','0101 Fondos Propios','0203 Donado') collate utf8_spanish2_ci default NULL,
  `fechaElaboracion` date default NULL,
  PRIMARY KEY  (`idEspecificacion`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_spanish2_ci;

--
-- Volcar la base de datos para la tabla `variacionpresupuestaria`
--

INSERT INTO `variacionpresupuestaria` (`idEspecificacion`, `FuenteFinanciamiento`, `fechaElaboracion`) VALUES
(2010, '0201 Fondo General', '2009-12-16');
